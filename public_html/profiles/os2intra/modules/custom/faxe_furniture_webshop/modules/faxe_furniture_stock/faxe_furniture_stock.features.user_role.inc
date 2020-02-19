<?php

/**
 * @file
 * faxe_furniture_stock.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function faxe_furniture_stock_user_default_roles() {
  $roles = array();

  // Exported role: Warehouse.
  $roles['Warehouse'] = array(
    'name' => 'Warehouse',
    'weight' => 9,
  );

  return $roles;
}
