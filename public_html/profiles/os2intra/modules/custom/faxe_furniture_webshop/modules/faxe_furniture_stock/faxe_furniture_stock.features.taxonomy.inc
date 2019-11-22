<?php

/**
 * @file
 * faxe_furniture_stock.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function faxe_furniture_stock_taxonomy_default_vocabularies() {
  return array(
    'faxe_furniture_category' => array(
      'name' => 'Furniture category',
      'machine_name' => 'faxe_furniture_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'furniture_stock_place' => array(
      'name' => 'Furniture stock place',
      'machine_name' => 'furniture_stock_place',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
