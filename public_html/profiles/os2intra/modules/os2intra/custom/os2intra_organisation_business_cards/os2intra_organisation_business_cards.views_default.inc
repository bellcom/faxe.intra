<?php

/**
 * @file
 * os2intra_organisation_business_cards.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function os2intra_organisation_business_cards_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'os2intra_organisation_business_cards_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'OS2Intra Organisation business cards';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'OS2Intra Organisation business cards';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'os2-box-body';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Felt: Ord i ordforråd: Navn */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['name']['element_class'] = 'os2-node-teaser-heading-title';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Felt: Ord i ordforråd: Tekst på visitkort */
  $handler->display->display_options['fields']['field_os2intra_bcard_text']['id'] = 'field_os2intra_bcard_text';
  $handler->display->display_options['fields']['field_os2intra_bcard_text']['table'] = 'field_data_field_os2intra_bcard_text';
  $handler->display->display_options['fields']['field_os2intra_bcard_text']['field'] = 'field_os2intra_bcard_text';
  $handler->display->display_options['fields']['field_os2intra_bcard_text']['label'] = '';
  $handler->display->display_options['fields']['field_os2intra_bcard_text']['element_class'] = 'os2-node-teaser-body-content';
  $handler->display->display_options['fields']['field_os2intra_bcard_text']['element_label_colon'] = FALSE;
  /* Felt: Ord i ordforråd: Business card keywords */
  $handler->display->display_options['fields']['field_os2intra_bcard_keywords']['id'] = 'field_os2intra_bcard_keywords';
  $handler->display->display_options['fields']['field_os2intra_bcard_keywords']['table'] = 'field_data_field_os2intra_bcard_keywords';
  $handler->display->display_options['fields']['field_os2intra_bcard_keywords']['field'] = 'field_os2intra_bcard_keywords';
  $handler->display->display_options['fields']['field_os2intra_bcard_keywords']['label'] = '';
  $handler->display->display_options['fields']['field_os2intra_bcard_keywords']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2intra_bcard_keywords']['element_label_colon'] = FALSE;
  /* Sorteringskriterie: Ord i ordforråd: Navn */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Kontekstuelt filter: Ord i ordforråd: Overordnet ord */
  $handler->display->display_options['arguments']['parent']['id'] = 'parent';
  $handler->display->display_options['arguments']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['arguments']['parent']['field'] = 'parent';
  $handler->display->display_options['arguments']['parent']['default_action'] = 'default';
  $handler->display->display_options['arguments']['parent']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['parent']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['parent']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['parent']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['parent']['summary_options']['items_per_page'] = '25';
  /* Filterkriterie: Ordforråd: Internt navn */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'os2intra_organisation_tax' => 'os2intra_organisation_tax',
  );
  /* Filterkriterie: Global: Kombinér felter filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
    'field_os2intra_bcard_text' => 'field_os2intra_bcard_text',
    'field_os2intra_bcard_keywords' => 'field_os2intra_bcard_keywords',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['os2intra_organisation_business_cards_block'] = array(
    t('Master'),
    t('OS2Intra Organisation business cards'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Alle'),
    t('Block'),
  );
  $export['os2intra_organisation_business_cards_block'] = $view;

  return $export;
}
