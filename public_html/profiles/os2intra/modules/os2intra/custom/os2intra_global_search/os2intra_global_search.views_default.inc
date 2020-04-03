<?php

/**
 * @file
 * os2intra_global_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function os2intra_global_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'os2intra_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_os2intra_multiindex';
  $view->human_name = 'OS2Intra search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sog';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '-1';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Søg';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'os2-box-body row.-equal';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Overskrift: Global: Resumé af resultat */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Søgresultater (@total)';
  /* Opførsel ved ingen resultater: Global: Tekstområde */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Ingen resultater';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Ingen resultater matchede din søgning.';
  $handler->display->display_options['empty']['area']['format'] = 'indhold';
  /* Felt: Ord i ordforråd: Navn (indexed) */
  $handler->display->display_options['fields']['taxonomy_term_name']['id'] = 'taxonomy_term_name';
  $handler->display->display_options['fields']['taxonomy_term_name']['table'] = 'search_api_index_os2intra_multiindex';
  $handler->display->display_options['fields']['taxonomy_term_name']['field'] = 'taxonomy_term_name';
  $handler->display->display_options['fields']['taxonomy_term_name']['label'] = '';
  $handler->display->display_options['fields']['taxonomy_term_name']['alter']['preserve_tags'] = '<strong>';
  $handler->display->display_options['fields']['taxonomy_term_name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['taxonomy_term_name']['element_class'] = 'os2-node-teaser-heading-title';
  $handler->display->display_options['fields']['taxonomy_term_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['taxonomy_term_name']['link_to_entity'] = 1;
  /* Felt: Indholdselement: Titel (indexed) */
  $handler->display->display_options['fields']['node_title']['id'] = 'node_title';
  $handler->display->display_options['fields']['node_title']['table'] = 'search_api_index_os2intra_multiindex';
  $handler->display->display_options['fields']['node_title']['field'] = 'node_title';
  $handler->display->display_options['fields']['node_title']['label'] = '';
  $handler->display->display_options['fields']['node_title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['node_title']['element_class'] = 'os2-node-teaser-heading-title';
  $handler->display->display_options['fields']['node_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['node_title']['link_to_entity'] = 1;
  /* Felt: Bruger: Efternavn (indexed) */
  $handler->display->display_options['fields']['user_field_name_last']['id'] = 'user_field_name_last';
  $handler->display->display_options['fields']['user_field_name_last']['table'] = 'search_api_index_os2intra_multiindex';
  $handler->display->display_options['fields']['user_field_name_last']['field'] = 'user_field_name_last';
  $handler->display->display_options['fields']['user_field_name_last']['label'] = '';
  $handler->display->display_options['fields']['user_field_name_last']['exclude'] = TRUE;
  $handler->display->display_options['fields']['user_field_name_last']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user_field_name_last']['type'] = 'text_plain';
  /* Felt: Bruger: Fornavn (indexed) */
  $handler->display->display_options['fields']['user_field_name_first']['id'] = 'user_field_name_first';
  $handler->display->display_options['fields']['user_field_name_first']['table'] = 'search_api_index_os2intra_multiindex';
  $handler->display->display_options['fields']['user_field_name_first']['field'] = 'user_field_name_first';
  $handler->display->display_options['fields']['user_field_name_first']['label'] = '';
  $handler->display->display_options['fields']['user_field_name_first']['exclude'] = TRUE;
  $handler->display->display_options['fields']['user_field_name_first']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user_field_name_first']['type'] = 'text_plain';
  /* Felt: Bruger: Navn (indexed) */
  $handler->display->display_options['fields']['user_name']['id'] = 'user_name';
  $handler->display->display_options['fields']['user_name']['table'] = 'search_api_index_os2intra_multiindex';
  $handler->display->display_options['fields']['user_name']['field'] = 'user_name';
  $handler->display->display_options['fields']['user_name']['label'] = '';
  $handler->display->display_options['fields']['user_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['user_name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['user_name']['element_class'] = 'os2-node-teaser-heading-title';
  $handler->display->display_options['fields']['user_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user_name']['link_to_entity'] = 0;
  /* Felt: Username */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Username';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[user_field_name_last]  [user_field_name_first] ';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'h3';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'os2-node-teaser-heading-title';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Felt: Indexed Multiple types: Entitetstype */
  $handler->display->display_options['fields']['item_type']['id'] = 'item_type';
  $handler->display->display_options['fields']['item_type']['table'] = 'search_api_index_os2intra_multiindex';
  $handler->display->display_options['fields']['item_type']['field'] = 'item_type';
  $handler->display->display_options['fields']['item_type']['label'] = '';
  $handler->display->display_options['fields']['item_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['item_type']['format_name'] = 1;
  /* Felt: Søg: Uddrag */
  $handler->display->display_options['fields']['search_api_excerpt']['id'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['table'] = 'search_api_index_os2intra_multiindex';
  $handler->display->display_options['fields']['search_api_excerpt']['field'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['label'] = '';
  $handler->display->display_options['fields']['search_api_excerpt']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['search_api_excerpt']['alter']['preserve_tags'] = '<strong></strong>';
  $handler->display->display_options['fields']['search_api_excerpt']['element_class'] = 'os2-node-teaser-body-content';
  $handler->display->display_options['fields']['search_api_excerpt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['link_to_entity'] = 0;
  /* Felt: Indexed Multiple types: Bundle */
  $handler->display->display_options['fields']['item_bundle']['id'] = 'item_bundle';
  $handler->display->display_options['fields']['item_bundle']['table'] = 'search_api_index_os2intra_multiindex';
  $handler->display->display_options['fields']['item_bundle']['field'] = 'item_bundle';
  $handler->display->display_options['fields']['item_bundle']['label'] = '';
  $handler->display->display_options['fields']['item_bundle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_bundle']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['item_bundle']['format_name'] = 1;
  /* Sorteringskriterie: Søg: Relevans */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_os2intra_multiindex';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Kontekstuelt filter: Indholdselement: Indholdselement ID (indexed) */
  $handler->display->display_options['arguments']['node_nid']['id'] = 'node_nid';
  $handler->display->display_options['arguments']['node_nid']['table'] = 'search_api_index_os2intra_multiindex';
  $handler->display->display_options['arguments']['node_nid']['field'] = 'node_nid';
  $handler->display->display_options['arguments']['node_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['node_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['node_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['node_nid']['break_phrase'] = TRUE;
  /* Kontekstuelt filter: Bruger: Bruger ID (indexed) */
  $handler->display->display_options['arguments']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['arguments']['user_uid']['table'] = 'search_api_index_os2intra_multiindex';
  $handler->display->display_options['arguments']['user_uid']['field'] = 'user_uid';
  $handler->display->display_options['arguments']['user_uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['user_uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['user_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user_uid']['break_phrase'] = TRUE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filterkriterie: Søg: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_os2intra_multiindex';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'search';
  $translatables['os2intra_search'] = array(
    t('Master'),
    t('Sog'),
    t('mere'),
    t('Søg'),
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
    t('Søgresultater (@total)'),
    t('Ingen resultater'),
    t('Ingen resultater matchede din søgning.'),
    t('[user_field_name_last]  [user_field_name_first] '),
    t('Alle'),
    t('Page'),
  );
  $export['os2intra_search'] = $view;

  return $export;
}
