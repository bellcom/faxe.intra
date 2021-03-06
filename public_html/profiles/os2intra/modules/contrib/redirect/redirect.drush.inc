<?php

/**
 * @file
 * Drush integration for the redirect module.
 */

/**
 * Implementation of hook_drush_command().
 */
function redirect_drush_command() {
  $items = array();
  $items['generate-redirects'] = array(
    'description' => 'Create redirects.',
    'drupal dependencies' => array('devel_generate'),
    'arguments' => array(
      'count' => 'Number of redirects to generate.',
    ),
    'options' => array(
      'delete' => 'Delete all redirects before generating new ones.',
    ),
  );
  $items['create-redirect'] = array(
    'description' => 'Create a redirect.',
    'arguments' => array(
      'source' => 'Path from which to redirect.',
      'destination' => 'Path or URL to which to redirect.',
    ),
    'options' => array(
      'language' => 'The language for which to redirect. Defaults to all.',
      'code' => "Redirect code, one of 30{0-7}, or 0 for the module's configured default. Defaults to 0.",
    ),
    'examples' => array(
      "drush create-redirect 'source' 'destination'" => 'Add a redirect from source to destination.',
      "drush create-redirect 'source' 'destination' --language=fr --code=302" => 'Add a 302 redirect from source to destination for the French language.',
    ),
  );

  return $items;
}

/**
 * Command callback. Validates and adds a redirect.
 *
 * @param string $source
 *   The path from which to redirect.
 * @param string $destination
 *   The path to which to redirect.
 */
function drush_redirect_create_redirect($source, $destination) {
  // Create redirect object and set initial values.
  $redirect = new stdClass();
  redirect_object_prepare($redirect, array(
    'source' => $source,
    'language' => drush_get_option('language', LANGUAGE_NONE),
    'redirect' => $destination,
    'status_code' => drush_get_option('code', 0),
  ));

  // Do some sanity checks.
  // Check that there there are no redirect loops.
  if (url($redirect->source) == url($redirect->redirect)) {
    return drush_set_error('redirect', t('You are attempting to redirect the page to itself. This would result in an infinite loop.'));
  }

  // Check if this redirect already exists.
  redirect_hash($redirect);
  if ($existing = redirect_load_by_hash($redirect->hash)) {
    if ($redirect->rid != $existing->rid) {
      return drush_set_error('redirect', t('The source path %source is already being redirected to %redirect.', array(
        '%source' => redirect_url($redirect->source, $redirect->source_options),
        '%redirect' => redirect_url($existing->redirect),
      )));
    }
  }

  // Save the redirect if there were no errors.
  redirect_save($redirect);
  drush_log(dt('Redirect from !source to !destination saved.', array('!source' => $redirect->source, '!destination' => $redirect->redirect)), 'success');
}

/**
 * Command callback. Generate a number of redirects.
 */
function drush_redirect_generate_redirects($count = NULL) {
  if (drush_generate_is_number($count) == FALSE) {
    return drush_set_error('DEVEL_GENERATE_INVALID_INPUT', t('Invalid number of redirects.'));
  }
  module_load_include('inc', 'redirect', 'redirect.generate');
  drush_generate_include_devel();
  redirect_run_unprogressive_batch('redirect_generate_redirects_batch_info', $count, drush_get_option('delete'));
}

/**
 * Perform an unprogressive batch process for CLI.
 */
function redirect_run_unprogressive_batch() {
  $batch = batch_get();
  if (!empty($batch)) {
    // If there is already something in the batch, don't run.
    return FALSE;
  }

  $args = func_get_args();
  $batch_callback = array_shift($args);

  if (!lock_acquire($batch_callback)) {
    return FALSE;
  }

  // Attempt to increase the execution time.
  drupal_set_time_limit(240);

  // Build the batch array.
  $batch = call_user_func_array($batch_callback, $args);
  batch_set($batch);

  // We need to manually set the progressive variable again.
  // @todo Remove when http://drupal.org/node/638712 is fixed.
  $batch =& batch_get();
  $batch['progressive'] = FALSE;

  // Run the batch process.
  batch_process();

  lock_release($batch_callback);
  return TRUE;
}
