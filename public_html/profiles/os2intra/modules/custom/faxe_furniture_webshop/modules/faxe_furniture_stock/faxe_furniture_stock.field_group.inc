<?php

/**
 * @file
 * faxe_furniture_stock.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function faxe_furniture_stock_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_furniture|node|faxe_furniture_product|form';
  $field_group->group_name = 'group_furniture';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'faxe_furniture_product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Furniture',
    'weight' => '0',
    'children' => array(
      0 => 'group_tekst',
      1 => 'group_images',
      2 => 'group_stock',
      3 => 'group_size',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-furniture field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_furniture|node|faxe_furniture_product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|faxe_furniture_product|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'faxe_furniture_product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_furniture';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '10',
    'children' => array(
      0 => 'field_os2intra_images',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-images field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_images|node|faxe_furniture_product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_size|node|faxe_furniture_product|form';
  $field_group->group_name = 'group_size';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'faxe_furniture_product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_furniture';
  $field_group->data = array(
    'label' => 'Size',
    'weight' => '11',
    'children' => array(
      0 => 'field_furniture_size',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_size|node|faxe_furniture_product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stock|node|faxe_furniture_product|form';
  $field_group->group_name = 'group_stock';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'faxe_furniture_product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_furniture';
  $field_group->data = array(
    'label' => 'Stock',
    'weight' => '12',
    'children' => array(
      0 => 'field_furniture_stock_amount',
      1 => 'field_furniture_stock_place',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-stock field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_stock|node|faxe_furniture_product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tekst|node|faxe_furniture_product|form';
  $field_group->group_name = 'group_tekst';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'faxe_furniture_product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_furniture';
  $field_group->data = array(
    'label' => 'Tekst',
    'weight' => '9',
    'children' => array(
      0 => 'field_furniture_description',
      1 => 'field_furniture_category',
      2 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tekst field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_tekst|node|faxe_furniture_product|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Furniture');
  t('Images');
  t('Size');
  t('Stock');
  t('Tekst');

  return $field_groups;
}
