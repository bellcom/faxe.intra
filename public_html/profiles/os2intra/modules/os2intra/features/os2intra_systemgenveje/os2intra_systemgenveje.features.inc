<?php
/**
 * @file
 * os2intra_systemgenveje.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os2intra_systemgenveje_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function os2intra_systemgenveje_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function os2intra_systemgenveje_flag_default_flags() {
  $flags = array();
  // Exported flag: "Viste systemgenveje".
  $flags['viste_systemgenveje'] = array(
    'entity_type' => 'node',
    'title' => 'Viste systemgenveje',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Skjul denne genvej',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Vis denne genvej',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'includeable' => 'includeable',
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'drupalgap' => 0,
      'list' => 0,
      'print' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'os2intra_systemgenveje',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function os2intra_systemgenveje_node_info() {
  $items = array(
    'systemgenveje' => array(
      'name' => t('systemgenveje'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
