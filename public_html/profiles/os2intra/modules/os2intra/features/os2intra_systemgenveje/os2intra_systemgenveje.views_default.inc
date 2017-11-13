<?php
/**
 * @file
 * os2intra_systemgenveje.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function os2intra_systemgenveje_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'os2intra_systemgenveje';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'OS2Intra Systemgenveje';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '-1';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_systemgenveje_icon' => 'field_systemgenveje_icon',
    'title' => 'title',
    'ops' => 'ops',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_systemgenveje_icon' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Flags: viste_systemgenveje */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'viste_systemgenveje';
  /* Field: Content: Icon */
  $handler->display->display_options['fields']['field_systemgenveje_icon']['id'] = 'field_systemgenveje_icon';
  $handler->display->display_options['fields']['field_systemgenveje_icon']['table'] = 'field_data_field_systemgenveje_icon';
  $handler->display->display_options['fields']['field_systemgenveje_icon']['field'] = 'field_systemgenveje_icon';
  $handler->display->display_options['fields']['field_systemgenveje_icon']['label'] = '';
  $handler->display->display_options['fields']['field_systemgenveje_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_systemgenveje_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_systemgenveje_icon']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'systemgenveje' => 'systemgenveje',
  );

  /* Display: Systemgenveje Tab */
  $handler = $view->new_display('block', 'Systemgenveje Tab', 'systemgenveje_tab');

  /* Display: Systemgenveje Block */
  $handler = $view->new_display('block', 'Systemgenveje Block', 'systemgenveje_block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: viste_systemgenveje */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'viste_systemgenveje';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Icon */
  $handler->display->display_options['fields']['field_systemgenveje_icon']['id'] = 'field_systemgenveje_icon';
  $handler->display->display_options['fields']['field_systemgenveje_icon']['table'] = 'field_data_field_systemgenveje_icon';
  $handler->display->display_options['fields']['field_systemgenveje_icon']['field'] = 'field_systemgenveje_icon';
  $handler->display->display_options['fields']['field_systemgenveje_icon']['label'] = '';
  $handler->display->display_options['fields']['field_systemgenveje_icon']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_systemgenveje_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_systemgenveje_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_systemgenveje_icon']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_systemgenveje_link']['id'] = 'field_systemgenveje_link';
  $handler->display->display_options['fields']['field_systemgenveje_link']['table'] = 'field_data_field_systemgenveje_link';
  $handler->display->display_options['fields']['field_systemgenveje_link']['field'] = 'field_systemgenveje_link';
  $handler->display->display_options['fields']['field_systemgenveje_link']['label'] = '';
  $handler->display->display_options['fields']['field_systemgenveje_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_systemgenveje_link']['alter']['text'] = '<a href="[field_systemgenveje_link-url]" target="_blank">[field_systemgenveje_icon] [title]</a>';
  $handler->display->display_options['fields']['field_systemgenveje_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_systemgenveje_link']['click_sort_column'] = 'url';
  $translatables['os2intra_systemgenveje'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('flag'),
    t('Systemgenveje Tab'),
    t('Systemgenveje Block'),
    t('<a href="[field_systemgenveje_link-url]" target="_blank">[field_systemgenveje_icon] [title]</a>'),
  );
  $export['os2intra_systemgenveje'] = $view;

  return $export;
}
