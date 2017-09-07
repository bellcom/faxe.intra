<?php
/**
 * Helper function to parse file contents to array with relevant info
 */
function _os2intra_user_import_process_file($file_path, $lines = FALSE) {
  // CSV field mapping
  // rewrite for settings page?
  $mapping =  variable_get('os2intra_mapping');
  $map_fallback = array(
    'ad_id'                 => 'os2intra_mapping_ad_id',
    'employee_id'           => 'os2intra_mapping_employee_id',
    'first_name'            => 'os2intra_mapping_first_name',
    'last_name'             => 'os2intra_mapping_last_name',
    'department'            => 'os2intra_mapping_department',
    'department_shortname'  => 'os2intra_mapping_department_shortname',
    'centre'                => 'os2intra_mapping_centre',
    'job_description'       =>'os2intra_mapping_job_description',
    'termination_date'      => 'os2intra_mapping_termination_date',
    'phone'                 => 'os2intra_mapping_phone',
    'mobile'                => 'os2intra_mapping_mobile',
    'email'                 => 'os2intra_mapping_email',
    'birthdate'             => 'os2intra_mapping_birthdate',
    'department_name'       => 'os2intra_mapping_department_name'
  );

  // Load data from file
  $csv = array_map(function($d) {
    return str_getcsv($d, variable_get('os2intra_user_import_delimiter'));
  }, file($file_path));
  $at_content = FALSE;

  foreach ($csv as $row) {

    // Look for where headings start and ignore everything before the headings.
    if (!$at_content
      && (!array_key_exists($mapping['os2intra_mapping_ad_id']['primary'], $row)
     || $row[$mapping['os2intra_mapping_ad_id']['primary']] != 'AD-ID')) {
      continue;
    }
    else {
      $at_content = TRUE;
    }
    // SKip if row has no user name
    //if ($row[variable_get('os2intra_mapping_ad_id')] == '') {
    //  continue;
   // }

    // Parse mapping
   /*foreach ($row as $key => $field) {
      // If there is a mapping for the key
      if ($map[$key]) {
        if (!empty($field)) {
          $mapped_row[$map[$key]] = _os2intra_user_import_sanitize_int($field);
        }
      }
    } */
    $mapped_row = array();
    foreach ($map_fallback as $field=> $variable) {

      if (!empty($row[$mapping[$variable]['primary']])) {
        $mapped_row[$field] = _os2intra_user_import_sanitize_int($row[$mapping[$variable]['primary']]);
      }
      else if ($mapping[$variable]['secondary'] == 'input') {
        $mapped_row[$field] = $mapping[$variable]['input'];
      }
      else if (is_numeric($mapping[$variable]['secondary'])){
        $mapped_row[$field] = _os2intra_user_import_sanitize_int($row[$mapping[$variable]['secondary']]);
      }
    }
   // SKip if row has no user name
    if ($mapped_row['ad_id'] == '') {
      continue;
    }
      $rows[] = $mapped_row;

      if($lines && $lines < count($rows)) {
        break;
      }

  }

  // Skip first row, headers
  unset($rows[0]);
  return $rows;
}
