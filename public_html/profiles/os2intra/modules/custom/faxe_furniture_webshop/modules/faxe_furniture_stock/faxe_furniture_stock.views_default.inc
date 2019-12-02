<?php

/**
 * @file
 * faxe_furniture_stock.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function faxe_furniture_stock_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'faxe_intra_furniture_stock';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Furniture stock';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Furniture stock';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '-1';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_os2intra_images' => 'field_os2intra_images',
    'title' => 'title',
    'field_furniture_category' => 'field_furniture_category',
    'field_furniture_stock_amount' => 'field_furniture_stock_amount',
    'field_furniture_stock_place' => 'field_furniture_stock_place',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['class'] = '';
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_os2intra_images' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_furniture_category' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_furniture_stock_amount' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_furniture_stock_place' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Overskrift: Global: Ufiltreret tekst */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<ul class="action-links"><li><a href="/node/add/faxe-furniture-product">Tilføj nyt produkt </a></li> </ul>';
  /* Felt: Indhold: Billeder */
  $handler->display->display_options['fields']['field_os2intra_images']['id'] = 'field_os2intra_images';
  $handler->display->display_options['fields']['field_os2intra_images']['table'] = 'field_data_field_os2intra_images';
  $handler->display->display_options['fields']['field_os2intra_images']['field'] = 'field_os2intra_images';
  $handler->display->display_options['fields']['field_os2intra_images']['label'] = '';
  $handler->display->display_options['fields']['field_os2intra_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2intra_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2intra_images']['settings'] = array(
    'image_style' => 'media_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2intra_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_os2intra_images']['delta_offset'] = '1';
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Category */
  $handler->display->display_options['fields']['field_furniture_category']['id'] = 'field_furniture_category';
  $handler->display->display_options['fields']['field_furniture_category']['table'] = 'field_data_field_furniture_category';
  $handler->display->display_options['fields']['field_furniture_category']['field'] = 'field_furniture_category';
  $handler->display->display_options['fields']['field_furniture_category']['label'] = 'Kategori';
  $handler->display->display_options['fields']['field_furniture_category']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Indhold: Tilgængelig mængde */
  $handler->display->display_options['fields']['field_furniture_stock_amount']['id'] = 'field_furniture_stock_amount';
  $handler->display->display_options['fields']['field_furniture_stock_amount']['table'] = 'field_data_field_furniture_stock_amount';
  $handler->display->display_options['fields']['field_furniture_stock_amount']['field'] = 'field_furniture_stock_amount';
  $handler->display->display_options['fields']['field_furniture_stock_amount']['settings'] = array(
    'thousand_separator' => '.',
    'prefix_suffix' => 1,
  );
  /* Felt: Indhold: Placering */
  $handler->display->display_options['fields']['field_furniture_stock_place']['id'] = 'field_furniture_stock_place';
  $handler->display->display_options['fields']['field_furniture_stock_place']['table'] = 'field_data_field_furniture_stock_place';
  $handler->display->display_options['fields']['field_furniture_stock_place']['field'] = 'field_furniture_stock_place';
  $handler->display->display_options['fields']['field_furniture_stock_place']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Redigér';
  /* Felt: Indhold: Link to delete content */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Slet';
  /* Sorteringskriterie: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filterkriterie: Indhold: Publiceringsstatus */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faxe_furniture_product' => 'faxe_furniture_product',
  );
  /* Filterkriterie: Indhold: Category (field_furniture_category) */
  $handler->display->display_options['filters']['field_furniture_category_tid']['id'] = 'field_furniture_category_tid';
  $handler->display->display_options['filters']['field_furniture_category_tid']['table'] = 'field_data_field_furniture_category';
  $handler->display->display_options['filters']['field_furniture_category_tid']['field'] = 'field_furniture_category_tid';
  $handler->display->display_options['filters']['field_furniture_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_furniture_category_tid']['expose']['operator_id'] = 'field_furniture_category_tid_op';
  $handler->display->display_options['filters']['field_furniture_category_tid']['expose']['label'] = 'Kategori';
  $handler->display->display_options['filters']['field_furniture_category_tid']['expose']['operator'] = 'field_furniture_category_tid_op';
  $handler->display->display_options['filters']['field_furniture_category_tid']['expose']['identifier'] = 'field_furniture_category_tid';
  $handler->display->display_options['filters']['field_furniture_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_furniture_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_furniture_category_tid']['vocabulary'] = 'faxe_furniture_category';
  /* Filterkriterie: Indhold: Titel */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
  );
  $handler->display->display_options['path'] = 'admin/content/furniture';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Møbler';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Furniture';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Møbeldatabase';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'row';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Publiceringsstatus */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faxe_furniture_product' => 'faxe_furniture_product',
  );
  /* Filterkriterie: Indhold: Tilgængelig mængde (field_furniture_stock_amount) */
  $handler->display->display_options['filters']['field_furniture_stock_amount_value']['id'] = 'field_furniture_stock_amount_value';
  $handler->display->display_options['filters']['field_furniture_stock_amount_value']['table'] = 'field_data_field_furniture_stock_amount';
  $handler->display->display_options['filters']['field_furniture_stock_amount_value']['field'] = 'field_furniture_stock_amount_value';
  $handler->display->display_options['filters']['field_furniture_stock_amount_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_furniture_stock_amount_value']['value']['value'] = '1';
  /* Filterkriterie: Indhold: Category (field_furniture_category) */
  $handler->display->display_options['filters']['field_furniture_category_tid']['id'] = 'field_furniture_category_tid';
  $handler->display->display_options['filters']['field_furniture_category_tid']['table'] = 'field_data_field_furniture_category';
  $handler->display->display_options['filters']['field_furniture_category_tid']['field'] = 'field_furniture_category_tid';
  $handler->display->display_options['filters']['field_furniture_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_furniture_category_tid']['expose']['operator_id'] = 'field_furniture_category_tid_op';
  $handler->display->display_options['filters']['field_furniture_category_tid']['expose']['label'] = 'Kategori';
  $handler->display->display_options['filters']['field_furniture_category_tid']['expose']['operator'] = 'field_furniture_category_tid_op';
  $handler->display->display_options['filters']['field_furniture_category_tid']['expose']['identifier'] = 'category';
  $handler->display->display_options['filters']['field_furniture_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_furniture_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_furniture_category_tid']['vocabulary'] = 'faxe_furniture_category';
  /* Filterkriterie: Indhold: Titel */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
  );
  $translatables['faxe_intra_furniture_stock'] = array(
    t('Master'),
    t('Furniture stock'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Antal elementer'),
    t('- Alle -'),
    t('Forskydning'),
    t('« første'),
    t('‹ forrige'),
    t('næste ›'),
    t('sidste »'),
    t('<ul class="action-links"><li><a href="/node/add/faxe-furniture-product">Tilføj nyt produkt </a></li> </ul>'),
    t('Titel'),
    t('Kategori'),
    t('Tilgængelig mængde'),
    t('Placering'),
    t('Redigér'),
    t('Slet'),
    t('Page'),
    t('Content pane'),
    t('Møbeldatabase'),
    t('View panes'),
  );
  $export['faxe_intra_furniture_stock'] = $view;

  $view = new view();
  $view->name = 'faxe_webshop_orders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FAXE webshop orders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'FAXE webshop orders';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_order_person_email' => 'field_order_person_email',
    'field_order_person_phone' => 'field_order_person_phone',
    'field_order_person_mobile_phone' => 'field_order_person_mobile_phone',
    'field_order_person_lokation' => 'field_order_person_lokation',
    'field_order_ordered_products' => 'field_order_ordered_products',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['class'] = '';
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_order_person_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_order_person_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_order_person_mobile_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_order_person_lokation' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_order_ordered_products' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Ordre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: E-mail */
  $handler->display->display_options['fields']['field_order_person_email']['id'] = 'field_order_person_email';
  $handler->display->display_options['fields']['field_order_person_email']['table'] = 'field_data_field_order_person_email';
  $handler->display->display_options['fields']['field_order_person_email']['field'] = 'field_order_person_email';
  /* Felt: Indhold: Telefon */
  $handler->display->display_options['fields']['field_order_person_phone']['id'] = 'field_order_person_phone';
  $handler->display->display_options['fields']['field_order_person_phone']['table'] = 'field_data_field_order_person_phone';
  $handler->display->display_options['fields']['field_order_person_phone']['field'] = 'field_order_person_phone';
  $handler->display->display_options['fields']['field_order_person_phone']['label'] = 'Fastnet tlf.';
  /* Felt: Indhold: Mobile phone */
  $handler->display->display_options['fields']['field_order_person_mobile_phone']['id'] = 'field_order_person_mobile_phone';
  $handler->display->display_options['fields']['field_order_person_mobile_phone']['table'] = 'field_data_field_order_person_mobile_phone';
  $handler->display->display_options['fields']['field_order_person_mobile_phone']['field'] = 'field_order_person_mobile_phone';
  $handler->display->display_options['fields']['field_order_person_mobile_phone']['label'] = 'Mobil tlf.';
  /* Felt: Indhold: Fysisk lokation */
  $handler->display->display_options['fields']['field_order_person_lokation']['id'] = 'field_order_person_lokation';
  $handler->display->display_options['fields']['field_order_person_lokation']['table'] = 'field_data_field_order_person_lokation';
  $handler->display->display_options['fields']['field_order_person_lokation']['field'] = 'field_order_person_lokation';
  /* Felt: Indhold: Produkt */
  $handler->display->display_options['fields']['field_order_ordered_products']['id'] = 'field_order_ordered_products';
  $handler->display->display_options['fields']['field_order_ordered_products']['table'] = 'field_data_field_order_ordered_products';
  $handler->display->display_options['fields']['field_order_ordered_products']['field'] = 'field_order_ordered_products';
  $handler->display->display_options['fields']['field_order_ordered_products']['label'] = 'Bestilte produkter';
  $handler->display->display_options['fields']['field_order_ordered_products']['settings'] = array(
    'add' => '',
    'edit' => '',
    'translate' => 'Oversæt',
    'delete' => '',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_order_ordered_products']['delta_offset'] = '0';
  /* Felt: Indhold: Opdateringsdato */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Sorteringskriterie: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filterkriterie: Indhold: Publiceringsstatus */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faxe_furniture_order' => 'faxe_furniture_order',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterie: Indhold: Titel */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Ordre';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Filterkriterie: Indhold: Fornavn (field_order_person_first_name) */
  $handler->display->display_options['filters']['field_order_person_first_name_value']['id'] = 'field_order_person_first_name_value';
  $handler->display->display_options['filters']['field_order_person_first_name_value']['table'] = 'field_data_field_order_person_first_name';
  $handler->display->display_options['filters']['field_order_person_first_name_value']['field'] = 'field_order_person_first_name_value';
  $handler->display->display_options['filters']['field_order_person_first_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_order_person_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_order_person_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_order_person_first_name_value']['expose']['operator_id'] = 'field_order_person_first_name_value_op';
  $handler->display->display_options['filters']['field_order_person_first_name_value']['expose']['label'] = 'Fornavn';
  $handler->display->display_options['filters']['field_order_person_first_name_value']['expose']['operator'] = 'field_order_person_first_name_value_op';
  $handler->display->display_options['filters']['field_order_person_first_name_value']['expose']['identifier'] = 'field_order_person_first_name_value';
  $handler->display->display_options['filters']['field_order_person_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Filterkriterie: Indhold: Efternavn (field_order_person_last_name) */
  $handler->display->display_options['filters']['field_order_person_last_name_value']['id'] = 'field_order_person_last_name_value';
  $handler->display->display_options['filters']['field_order_person_last_name_value']['table'] = 'field_data_field_order_person_last_name';
  $handler->display->display_options['filters']['field_order_person_last_name_value']['field'] = 'field_order_person_last_name_value';
  $handler->display->display_options['filters']['field_order_person_last_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_order_person_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_order_person_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_order_person_last_name_value']['expose']['operator_id'] = 'field_order_person_last_name_value_op';
  $handler->display->display_options['filters']['field_order_person_last_name_value']['expose']['label'] = 'Efternavn';
  $handler->display->display_options['filters']['field_order_person_last_name_value']['expose']['operator'] = 'field_order_person_last_name_value_op';
  $handler->display->display_options['filters']['field_order_person_last_name_value']['expose']['identifier'] = 'field_order_person_last_name_value';
  $handler->display->display_options['filters']['field_order_person_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/orders';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Faxe webshop orders';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['faxe_webshop_orders'] = array(
    t('Master'),
    t('FAXE webshop orders'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Antal elementer'),
    t('- Alle -'),
    t('Forskydning'),
    t('« første'),
    t('‹ forrige'),
    t('næste ›'),
    t('sidste »'),
    t('Ordre'),
    t('E-mail'),
    t('Fastnet tlf.'),
    t('Mobil tlf.'),
    t('Fysisk lokation'),
    t('Bestilte produkter'),
    t('Opdateringsdato'),
    t('Fornavn'),
    t('Efternavn'),
    t('Page'),
  );
  $export['faxe_webshop_orders'] = $view;

  return $export;
}
