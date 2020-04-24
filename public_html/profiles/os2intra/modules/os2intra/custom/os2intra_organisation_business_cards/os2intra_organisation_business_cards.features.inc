<?php

/**
 * @file
 * os2intra_organisation_business_cards.features.inc
 */

/**
 * Implements hook_views_api().
 */
function os2intra_organisation_business_cards_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0",
    'path' => drupal_get_path('module', 'os2intra_organisation_business_cards'),
    'template path' => drupal_get_path('module', 'os2intra_organisation_business_cards') . '/templates',
   );
}

