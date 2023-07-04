<?php

/**
 * @file
 * os2intra_content_types.features.hierarchical_select.inc
 */

/**
 * Implements hook_hierarchical_select_default_configs().
 */
function os2intra_content_types_hierarchical_select_default_configs() {
$configs = array();
$config = array(
  'save_lineage' => 0,
  'enforce_deepest' => 0,
  'resizable' => 1,
  'level_labels' => array(
    'status' => 0,
    'labels' => array(),
  ),
  'dropbox' => array(
    'status' => 0,
    'title' => 'All selections',
    'limit' => 0,
    'reset_hs' => 1,
    'sort' => 1,
  ),
  'editability' => array(
    'status' => 0,
    'item_types' => array(),
    'allowed_levels' => array(),
    'allow_new_levels' => 0,
    'max_levels' => 3,
  ),
  'entity_count' => array(
    'enabled' => 0,
    'require_entity' => 0,
    'settings' => array(
      'count_children' => 0,
      'entity_types' => array(
        'blame' => array(
          'count_blame' => array(
            'blame' => 0,
          ),
        ),
        'comment' => array(
          'count_comment' => array(
            'comment_node_os2intra_org_group_unit' => 0,
            'comment_node_event' => 0,
            'comment_node_os2intra_canteen_menu' => 0,
            'comment_node_os2intra_group' => 0,
            'comment_node_it_vejledning' => 0,
            'comment_node_node_basket' => 0,
            'comment_node_post' => 0,
            'comment_node_os2intra_message_notification' => 0,
            'comment_node_os2intra_base_page' => 0,
            'comment_node_wiki' => 0,
            'comment_node_os2intra_referat' => 0,
            'comment_node_os2web_base_selfservice_link' => 0,
            'comment_node_webform' => 0,
            'comment_node_spotbox' => 0,
            'comment_node_systemgenveje' => 0,
          ),
        ),
        'field_collection_item' => array(
          'count_field_collection_item' => array(
            'field_os2intra_base_vejledning' => 0,
            'field_os2intra_paragraph' => 0,
          ),
        ),
        'flagging' => array(
          'count_flagging' => array(
            'os2intra_flag_node_like' => 0,
            'papirkurv' => 0,
            'os2intra_flag_node_old' => 0,
            'tilmeld_gruppe' => 0,
            'os2intra_flag_info_til_alle' => 0,
            'subscribe_node' => 0,
            'email_node' => 0,
            'subscribe_term' => 0,
            'subscribe_og' => 0,
            'email_og' => 0,
            'email_term' => 0,
            'viste_systemgenveje' => 0,
          ),
        ),
        'message_type_category' => array(
          'count_message_type_category' => array(
            'message_type_category' => 0,
          ),
        ),
        'message_type' => array(
          'count_message_type' => array(
            'message_type' => 0,
          ),
        ),
        'message' => array(
          'count_message' => array(
            'os2intra_msgtp_afdelingsindhold' => 0,
          ),
        ),
        'node' => array(
          'count_node' => array(
            'os2intra_org_group_unit' => 'os2intra_org_group_unit',
            'event' => 'event',
            'os2intra_canteen_menu' => 'os2intra_canteen_menu',
            'os2intra_group' => 'os2intra_group',
            'it_vejledning' => 'it_vejledning',
            'node_basket' => 'node_basket',
            'post' => 'post',
            'os2intra_message_notification' => 'os2intra_message_notification',
            'os2intra_base_page' => 'os2intra_base_page',
            'wiki' => 'wiki',
            'os2intra_referat' => 'os2intra_referat',
            'os2web_base_selfservice_link' => 'os2web_base_selfservice_link',
            'webform' => 'webform',
            'spotbox' => 'spotbox',
            'systemgenveje' => 'systemgenveje',
          ),
        ),
        'og_membership_type' => array(
          'count_og_membership_type' => array(
            'og_membership_type' => 0,
          ),
        ),
        'og_membership' => array(
          'count_og_membership' => array(
            'og_membership_type_default' => 0,
            'organisatorisk' => 0,
          ),
        ),
        'file' => array(
          'count_file' => array(
            'image' => 0,
            'video' => 0,
            'audio' => 0,
            'document' => 0,
          ),
        ),
        'taxonomy_term' => array(
          'count_taxonomy_term' => array(
            'os2intra_canteen' => 0,
            'os2web_base_tax_site_structure' => 0,
            'topics' => 0,
            'os2web_base_tax_promoteto' => 0,
            'os2web_taxonomies_tax_comittee' => 0,
            'os2web_taxonomies_tax_editor_tag' => 0,
            'os2web_taxonomies_tax_kle' => 0,
            'os2web_taxonomies_tax_places' => 0,
            'os2web_taxonomies_tax_politics' => 0,
            'os2web_taxonomies_tax_portal_cat' => 0,
            'os2web_taxonomies_tax_user_pos' => 0,
            'tags' => 0,
            'os2intra_organisation_tax' => 0,
            'user_hobbies' => 0,
            'user_jobtitle' => 0,
            'user_skills' => 0,
            'indlaegstyper' => 0,
            'begivenhedstyper' => 0,
            'os2web_taxonomies_tax_org' => 0,
            'media_folders' => 0,
          ),
        ),
        'user' => array(
          'count_user' => array(
            'user' => 0,
          ),
        ),
        'webform_workflow_state' => array(
          'count_webform_workflow_state' => array(
            'webform_workflow_state' => 0,
          ),
        ),
        'rules_config' => array(
          'count_rules_config' => array(
            'rules_config' => 0,
          ),
        ),
      ),
    ),
  ),
  'animation_delay' => 400,
  'special_items' => array(),
  'render_flat_select' => 0,
  'config_id' => 'taxonomy-field_os2intra_base_structure',
);

$configs['taxonomy-field_os2intra_base_structure'] = $config;
$config = array(
  'save_lineage' => 0,
  'enforce_deepest' => 0,
  'resizable' => 0,
  'level_labels' => array(
    'status' => 0,
    'labels' => array(
      '0' => '',
      '1' => '',
      '2' => '',
    ),
  ),
  'dropbox' => array(
    'status' => 0,
    'title' => 'All selections',
    'limit' => 0,
    'reset_hs' => 1,
    'sort' => 1,
  ),
  'editability' => array(
    'status' => 0,
    'item_types' => array(
      '0' => '',
      '1' => '',
      '2' => '',
    ),
    'allowed_levels' => array(
      '0' => 0,
      '1' => 0,
      '2' => 0,
    ),
    'allow_new_levels' => 0,
    'max_levels' => 0,
  ),
  'entity_count' => array(
    'enabled' => 0,
    'require_entity' => 0,
    'settings' => array(
      'count_children' => 0,
      'entity_types' => array(
        'blame' => array(
          'count_blame' => array(
            'blame' => 0,
          ),
        ),
        'comment' => array(
          'count_comment' => array(
            'comment_node_os2intra_org_group_unit' => 0,
            'comment_node_event' => 0,
            'comment_node_os2intra_canteen_menu' => 0,
            'comment_node_os2intra_group' => 0,
            'comment_node_it_vejledning' => 0,
            'comment_node_node_basket' => 0,
            'comment_node_post' => 0,
            'comment_node_os2intra_message_notification' => 0,
            'comment_node_os2intra_base_page' => 0,
            'comment_node_wiki' => 0,
            'comment_node_os2intra_referat' => 0,
            'comment_node_os2web_base_selfservice_link' => 0,
            'comment_node_webform' => 0,
            'comment_node_spotbox' => 0,
            'comment_node_systemgenveje' => 0,
          ),
        ),
        'field_collection_item' => array(
          'count_field_collection_item' => array(
            'field_os2intra_base_vejledning' => 0,
            'field_os2intra_paragraph' => 0,
          ),
        ),
        'flagging' => array(
          'count_flagging' => array(
            'os2intra_flag_node_like' => 0,
            'papirkurv' => 0,
            'os2intra_flag_node_old' => 0,
            'tilmeld_gruppe' => 0,
            'os2intra_flag_info_til_alle' => 0,
            'subscribe_node' => 0,
            'email_node' => 0,
            'subscribe_term' => 0,
            'subscribe_og' => 0,
            'email_og' => 0,
            'email_term' => 0,
            'viste_systemgenveje' => 0,
          ),
        ),
        'message_type_category' => array(
          'count_message_type_category' => array(
            'message_type_category' => 0,
          ),
        ),
        'message_type' => array(
          'count_message_type' => array(
            'message_type' => 0,
          ),
        ),
        'message' => array(
          'count_message' => array(
            'os2intra_msgtp_afdelingsindhold' => 0,
          ),
        ),
        'node' => array(
          'count_node' => array(
            'os2intra_org_group_unit' => 'os2intra_org_group_unit',
            'event' => 'event',
            'os2intra_canteen_menu' => 'os2intra_canteen_menu',
            'os2intra_group' => 'os2intra_group',
            'it_vejledning' => 'it_vejledning',
            'node_basket' => 'node_basket',
            'post' => 'post',
            'os2intra_message_notification' => 'os2intra_message_notification',
            'os2intra_base_page' => 'os2intra_base_page',
            'wiki' => 'wiki',
            'os2intra_referat' => 'os2intra_referat',
            'os2web_base_selfservice_link' => 'os2web_base_selfservice_link',
            'webform' => 'webform',
            'spotbox' => 'spotbox',
            'systemgenveje' => 'systemgenveje',
          ),
        ),
        'og_membership_type' => array(
          'count_og_membership_type' => array(
            'og_membership_type' => 0,
          ),
        ),
        'og_membership' => array(
          'count_og_membership' => array(
            'og_membership_type_default' => 0,
            'organisatorisk' => 0,
          ),
        ),
        'file' => array(
          'count_file' => array(
            'image' => 0,
            'video' => 0,
            'audio' => 0,
            'document' => 0,
          ),
        ),
        'taxonomy_term' => array(
          'count_taxonomy_term' => array(
            'os2intra_canteen' => 0,
            'os2web_base_tax_site_structure' => 0,
            'topics' => 0,
            'os2web_base_tax_promoteto' => 0,
            'os2web_taxonomies_tax_comittee' => 0,
            'os2web_taxonomies_tax_editor_tag' => 0,
            'os2web_taxonomies_tax_kle' => 0,
            'os2web_taxonomies_tax_places' => 0,
            'os2web_taxonomies_tax_politics' => 0,
            'os2web_taxonomies_tax_portal_cat' => 0,
            'os2web_taxonomies_tax_user_pos' => 0,
            'tags' => 0,
            'os2intra_organisation_tax' => 0,
            'user_hobbies' => 0,
            'user_jobtitle' => 0,
            'user_skills' => 0,
            'indlaegstyper' => 0,
            'begivenhedstyper' => 0,
            'os2web_taxonomies_tax_org' => 0,
            'media_folders' => 0,
          ),
        ),
        'user' => array(
          'count_user' => array(
            'user' => 0,
          ),
        ),
        'webform_workflow_state' => array(
          'count_webform_workflow_state' => array(
            'webform_workflow_state' => 0,
          ),
        ),
        'rules_config' => array(
          'count_rules_config' => array(
            'rules_config' => 0,
          ),
        ),
      ),
    ),
  ),
  'animation_delay' => 400,
  'special_items' => array(),
  'render_flat_select' => 0,
  'config_id' => 'taxonomy-field_os2web_base_field_kle_ref',
);

$configs['taxonomy-field_os2web_base_field_kle_ref'] = $config;
return $configs;
}
