<?php
/**
 * Form callback for settings
 */
function os2intra_user_import_settings() {
  drupal_add_css(drupal_get_path('module', 'os2intra_user_import') . '/css/os2intra_user_import.css');
  drupal_add_js(drupal_get_path('module', 'os2intra_user_import') . '/js/os2intra_user_import.js');
 $import_dir = variable_get('os2intra_user_import_dir', 'private://user_import');

    $realpath = '';

    $filename = variable_get('os2intra_user_import_file_name', 'FK-user_import');
    $files = file_scan_directory($import_dir, '/' . $filename . '.csv/');
    $dir = reset($files);
    if ($dir) {
      $realpath = drupal_realpath($dir->uri);
    }

    if (file_exists($realpath)) {
        $users_array = _os2intra_user_import_process_file($realpath, 1);
        $users =  reset($users_array);
     }
    else{
      drupal_set_message('Csv file is not exists','warning');
    }
   $csv_cols = array(
    'none' => t('None'),
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
  );
$csv_cols_fallback_1 = array(
    'none' => t('None'),
    'input' => t('Input'),
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
  );
  $form['placeholder'] = array(
    '#type'   => 'item',
    '#markup' => t('This module does not provide a cron hook. This has to be set up manually, by adding the import script to the crontab'),
  );

  $form['os2intra_user_import_enable'] = array(
    '#title'         => t('Enable user import'),
    '#type'          => 'checkbox',
    '#default_value' => variable_get('os2intra_user_import_enable', FALSE)
  );

  $form['os2intra_user_import_dir'] = array(
    '#title'         => t('Directory containing CSV with users'),
    '#type'          => 'textfield',
    '#required'      => TRUE,
    '#description'   => t('ex. private://user_import'),
    '#default_value' => variable_get('os2intra_user_import_dir', 'private://user_import')
  );
  $form['os2intra_user_import_file_name'] = array(
    '#title'         => t('CSV file name'),
    '#type'          => 'textfield',
    '#required'      => TRUE,
    '#description'   => t('ex. FK-user_import (without extension .csv, without space)'),
    '#default_value' => variable_get('os2intra_user_import_file_name', 'FK-user_import'),
  );
  $form['os2intra_user_import_delimiter'] = array(
    '#title'         => t('CSV delimiter'),
    '#type'          => 'textfield',
    '#description'   => t('The delimiter used to separate values in the CSV, ex. a semicolon, a comma or \t (tab)'),
    '#default_value' => variable_get('os2intra_user_import_delimiter', ';'),
  );

  $form['os2intra_user_default_groups'] = array(
    '#title'         => t('Node ids (nid) of default OG groups, that should be added to every imported used'),
    '#type'          => 'textfield',
    '#description'   => t('CSV, ex. 1,2,3'),
    '#default_value' => variable_get('os2intra_user_default_groups')
  );

  $form['os2intra_user_notification_email'] = array(
    '#title'         => t('Email address that should be notified when new departments are created'),
    '#type'          => 'textfield',
    '#default_value' => variable_get('os2intra_user_notification_email', variable_get('site_mail')),
  );

  $form['os2intra_user_import_og_role_id_parent'] = array(
    '#title'         => t('Parent OG Role Grant ID'),
    '#type'          => 'textfield',
    '#default_value' => variable_get('os2intra_user_import_og_role_id_parent', 14),
    '#description'   => t('ID of the group role to grant the user, when added to parent groups.'),
  );

  $form['os2intra_user_import_og_role_id_user'] = array(
    '#title'         => t('Primary OG Role Grant ID'),
    '#type'          => 'textfield',
    '#default_value' => variable_get('os2intra_user_import_og_role_id_primary', 16),
    '#description'   => t('ID of the group role to grant the user, when added to primary group.'),
  );

  $form['os2intra_user_import_og_role_id_manager'] = array(
    '#title'         => t('Manager OG Role Grant ID'),
    '#type'          => 'textfield',
    '#default_value' => variable_get('os2intra_user_import_og_role_id_manager', 15),
    '#description'   => t('ID of the group role to grant the user, when added to manager group.'),
  );

  $form['os2intra_user_import_authmap_name_suffix'] = array(
    '#title'         => t("Suffix used on the column 'authname' in the authmap table"),
    '#type'          => 'textfield',
    '#default_value' => variable_get('os2intra_user_import_authmap_name_suffix'),
    '#description'   => t("For example '@fredericia.dk'"),
  );

  $form['os2intra_mapping'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Mapping'),
    '#collapsible'   => FALSE,
    '#tree'          => TRUE,
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-fieldset')
    )
  );
  $form['os2intra_mapping']['description'] = array(
    '#type'   => 'item',
    '#markup' => t('Select columns in the CSV file corresponding to the data'),
  );
  $form['os2intra_mapping']['os2intra_mapping_ad_id'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE,
  );
 $mapping = variable_get('os2intra_mapping');
  $form['os2intra_mapping']['os2intra_mapping_ad_id']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('AD id'),
    '#required'      => TRUE,
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_ad_id']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_ad_id']['secondary'] = array(
    '#type'          => 'select',
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_ad_id']['secondary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )
  );
   $form['os2intra_mapping']['os2intra_mapping_ad_id']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_ad_id']['input'],
  );
   $form['os2intra_mapping']['os2intra_mapping_ad_id']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['ad_id'])) ? $users['ad_id'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['os2intra_mapping']['os2intra_mapping_first_name'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE
  );
  $form['os2intra_mapping']['os2intra_mapping_first_name']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('Firstname'),
    '#required'      => TRUE,
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_first_name']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_first_name']['secondary'] = array(
    '#type'          => 'select',
    '#required'      => TRUE,
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_first_name']['secondary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_first_name']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_first_name']['input'],
  );
  $form['os2intra_mapping']['os2intra_mapping_first_name']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['first_name'])) ? $users['first_name'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['os2intra_mapping']['os2intra_mapping_last_name'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE
  );
  $form['os2intra_mapping']['os2intra_mapping_last_name']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('Lastname'),
    '#required'      => TRUE,
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_last_name']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_last_name']['secondary'] = array(
    '#type'          => 'select',
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_last_name']['secondary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_last_name']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_last_name']['input'],
  );
  $form['os2intra_mapping']['os2intra_mapping_last_name']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['last_name'])) ? $users['last_name'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['os2intra_mapping']['os2intra_mapping_department'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE
  );
  $form['os2intra_mapping']['os2intra_mapping_department']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('Department'),
    '#required'      => TRUE,
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_department']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_department']['secondary'] = array(
    '#type'          => 'select',
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_department']['secondary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_department']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_department']['input'],
  );
  $form['os2intra_mapping']['os2intra_mapping_department']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['department'])) ? $users['department'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['os2intra_mapping']['os2intra_mapping_department_shortname'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE
  );
  $form['os2intra_mapping']['os2intra_mapping_department_shortname']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('Department short name'),
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_department_shortname']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
    $form['os2intra_mapping']['os2intra_mapping_department_shortname']['secondary'] = array(
    '#type'          => 'select',
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_department_shortname']['secondary'],
      '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_department_shortname']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_department_shortname']['input'],
  );
  $form['os2intra_mapping']['os2intra_mapping_department_shortname']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['department_shortname'])) ? $users['department_shortname'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['os2intra_mapping']['os2intra_mapping_centre'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE
  );
  $form['os2intra_mapping']['os2intra_mapping_centre']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('Centre'),
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_centre']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
   $form['os2intra_mapping']['os2intra_mapping_centre']['secondary'] = array(
    '#type'          => 'select',
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_centre']['secondary'],
     '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_centre']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_centre']['input'],
  );
  $form['os2intra_mapping']['os2intra_mapping_centre']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['centre'])) ? $users['centre'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['os2intra_mapping']['os2intra_mapping_employee_id'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE
  );
  $form['os2intra_mapping']['os2intra_mapping_employee_id']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('Employee id'),
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_employee_id']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_employee_id']['secondary'] = array(
    '#type'          => 'select',
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_employee_id']['secondary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_employee_id']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_employee_id']['input'],
  );
  $form['os2intra_mapping']['os2intra_mapping_employee_id']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['employee_id'])) ? $users['employee_id'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['os2intra_mapping']['os2intra_mapping_job_description'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE
  );
  $form['os2intra_mapping']['os2intra_mapping_job_description']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('Job description'),
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_job_description']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_job_description']['secondary'] = array(
    '#type'          => 'select',
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_job_description']['secondary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_job_description']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_job_description']['input'],
  );
  $form['os2intra_mapping']['os2intra_mapping_job_description']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['job_description'])) ? $users['job_description'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['os2intra_mapping']['os2intra_mapping_termination_date'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE
  );
  $form['os2intra_mapping']['os2intra_mapping_termination_date']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('Termination date'),
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_termination_date']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_termination_date']['secondary'] = array(
    '#type'          => 'select',
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_termination_date']['secondary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_termination_date']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_termination_date']['input'],
  );
  $form['os2intra_mapping']['os2intra_mapping_termination_date']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['termination_date'])) ? $users['termination_date'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['os2intra_mapping']['os2intra_mapping_phone'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE
  );
  $form['os2intra_mapping']['os2intra_mapping_phone']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('Phone Number'),
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_phone']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_phone']['secondary'] = array(
    '#type'          => 'select',
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_phone']['secondary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )

  );
  $form['os2intra_mapping']['os2intra_mapping_phone']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_phone']['input'],
  );
  $form['os2intra_mapping']['os2intra_mapping_phone']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['phone'])) ? $users['phone'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['os2intra_mapping']['os2intra_mapping_mobile'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE
  );
  $form['os2intra_mapping']['os2intra_mapping_mobile']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('Mobile Number'),
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_mobile']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_mobile']['secondary'] = array(
    '#type'          => 'select',
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_mobile']['secondary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_mobile']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_mobile']['input'],
  );
  $form['os2intra_mapping']['os2intra_mapping_mobile']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['mobile'])) ? $users['mobile'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['os2intra_mapping']['os2intra_mapping_email'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE
  );
  $form['os2intra_mapping']['os2intra_mapping_email']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('Email Address'),
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_email']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_email']['secondary'] = array(
    '#type'          => 'select',
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_email']['secondary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )

  );
  $form['os2intra_mapping']['os2intra_mapping_email']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_email']['input'],
  );
  $form['os2intra_mapping']['os2intra_mapping_email']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['email'])) ? $users['email'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['os2intra_mapping']['os2intra_mapping_birthdate'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE
  );
  $form['os2intra_mapping']['os2intra_mapping_birthdate']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('Birthdate'),
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_birthdate']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_birthdate']['secondary'] = array(
    '#type'          => 'select',
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_birthdate']['secondary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_birthdate']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_birthdate']['input'],
  );
  $form['os2intra_mapping']['os2intra_mapping_birthdate']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['birthdate'])) ? $users['birthdate'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['os2intra_mapping']['os2intra_mapping_department_name'] = array(
    '#type'          => 'fieldset',
    '#tree'          => TRUE
  );
  $form['os2intra_mapping']['os2intra_mapping_department_name']['primary'] = array(
    '#type'          => 'select',
    '#title'         => t('Department name'),
    '#options'       => $csv_cols,
    '#default_value' => $mapping['os2intra_mapping_department_name']['primary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-primary-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_department_name']['secondary'] = array(
    '#type'          => 'select',
    '#options'       => $csv_cols_fallback_1,
    '#default_value' => $mapping['os2intra_mapping_department_name']['secondary'],
    '#attributes'    => array(
      'class'=> array('os2intra-mapping-fallback-field')
    )
  );
  $form['os2intra_mapping']['os2intra_mapping_department_name']['input'] = array(
    '#type'          => 'textfield',
    '#default_value' => $mapping['os2intra_mapping_department_name']['input'],
  );
  $form['os2intra_mapping']['os2intra_mapping_department_name']['markup'] = array(
    '#type'   => 'item',
    '#markup' => (isset($users['department_name'])) ? $users['department_name'] : '',
    '#prefix' => '<div class="os2intra-mapping-markup-field">',
    '#suffix' => '</div>',
  );
  $form['cleanup_help_block'] = array(
    '#type'   => 'item',
    '#title'  => t('Cleanup script'),
    '#markup' => '<ul><li>Deletes all terms in the vocabulary "os2intra_organization_tax"</li><li>Deletes all users with only one role "authenticated user"</li></ul><br>Run using: Run using drush scr ../scripts/delete_imported_data.php',
  );
  return system_settings_form($form);
}

/**
 * Implements hook_form_validate()
 */
function os2intra_user_import_settings_validate(&$form, &$form_state) {
  $values = array();
  foreach ($form_state['values']['os2intra_mapping'] as $field => $value) {
      // If same column is selected twice throw error
      if (in_array($value['primary'], $values) && $value['primary'] != 'none') {
        form_set_error('os2intra_mapping]['. $field . '][primary', t('Cannot use column twice'));
      }
      if (in_array($value['secondary'], $values) && $value['secondary'] != 'none' &&  $value['secondary'] != 'input') {
        form_set_error( 'os2intra_mapping]['. $field . '][secondary', t('Cannot use column twice'));
      }

      $values[] = $value['primary'];
      $values[] = $value['secondary'];

  }

  if ($form_state['values']['os2intra_user_default_groups']) {
    $default_groups = explode(',', $form_state['values']['os2intra_user_default_groups']);
    foreach ($default_groups as $group) {
      $node = node_load($group);
      if (!$node || $node->type != 'os2intra_org_group_unit') {
        form_set_error('os2intra_user_default_groups', t('Must be a valid NID of type organic groups (OG)'));
      }
    }
  }
}
