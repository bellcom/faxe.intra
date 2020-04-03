<?php

/**
 * @file
 * os2intra_global_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os2intra_global_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function os2intra_global_search_default_search_api_index() {
  $items = array();
  $items['os2intra_multiindex'] = entity_import('search_api_index', '{
    "name" : "OS2intra multiindex",
    "machine_name" : "os2intra_multiindex",
    "description" : null,
    "server" : "elasticsearch_server",
    "item_type" : "multiple",
    "options" : {
      "datasource" : { "types" : [ "user", "node", "taxonomy_term" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "index_name" : {
        "index" : "os2intra_multi_index",
        "cluster_id" : "elasticsearch_cluster"
      },
      "collect_index_statistics" : 0,
      "log_only_not_found" : 0,
      "index_statistics_ttl" : "365d",
      "fields" : {
        "item_type" : { "type" : "string" },
        "node" : { "type" : "integer", "entity_type" : "node" },
        "node:author" : { "type" : "integer", "entity_type" : "user" },
        "node:body:value" : { "type" : "text", "boost" : "3.0" },
        "node:changed" : { "type" : "date" },
        "node:created" : { "type" : "date" },
        "node:field_os2intra_base_structure" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_os2intra_base_structure:name" : { "type" : "text" },
        "node:field_os2intra_paragraph:field_os2intra_paragraph_text:value" : { "type" : "list\\u003Ctext\\u003E", "boost" : "3.0" },
        "node:field_os2intra_paragraph:field_os2intra_paragraph_title" : { "type" : "list\\u003Ctext\\u003E" },
        "node:field_os2web_base_field_intro" : { "type" : "text", "boost" : "2.0" },
        "node:nid" : { "type" : "integer" },
        "node:og_group_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "node:title" : { "type" : "text" },
        "node:type" : { "type" : "string" },
        "os2intra_global_search_index_department" : { "type" : "text" },
        "os2intra_global_search_index_item_type" : { "type" : "text" },
        "os2intra_global_search_index_section" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "taxonomy_term" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "taxonomy_term:description" : { "type" : "text", "boost" : "3.0" },
        "taxonomy_term:name" : { "type" : "text" },
        "taxonomy_term:tid" : { "type" : "integer" },
        "taxonomy_term:vocabulary" : { "type" : "integer", "entity_type" : "taxonomy_vocabulary" },
        "user" : { "type" : "integer", "entity_type" : "user" },
        "user:field_name_first" : { "type" : "text" },
        "user:field_name_last" : { "type" : "text" },
        "user:field_os2intra_user_bio:value" : { "type" : "text", "boost" : "0.3" },
        "user:field_os2intra_user_competences" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "user:field_os2intra_user_titles" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "user:name" : { "type" : "text" },
        "user:og_user_node" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "user:uid" : { "type" : "integer" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "node:os2intra_org_group_unit" : "node:os2intra_org_group_unit",
              "node:event" : "node:event",
              "node:os2intra_canteen_menu" : "node:os2intra_canteen_menu",
              "node:os2intra_group" : "node:os2intra_group",
              "node:it_vejledning" : "node:it_vejledning",
              "node:node_basket" : "node:node_basket",
              "node:post" : "node:post",
              "node:os2intra_base_page" : "node:os2intra_base_page",
              "node:wiki" : "node:wiki",
              "node:os2intra_referat" : "node:os2intra_referat",
              "node:webform" : "node:webform",
              "node:systemgenveje" : "node:systemgenveje",
              "taxonomy_term:os2web_base_tax_site_structure" : "taxonomy_term:os2web_base_tax_site_structure",
              "taxonomy_term:os2intra_organisation_tax" : "taxonomy_term:os2intra_organisation_tax"
            }
          }
        },
        "search_api_alter_role_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "roles" : [] }
        },
        "bellcom_elasticsearch_exclude_unpublished_content_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "exclude_nodes" : 1, "exclude_field_collection_item" : 0 }
        },
        "os2intra_global_search_index_department_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "os2intra_organisation_taxonomy_top_term_tid" : "13943" }
        },
        "os2intra_global_search_index_item_type_alter_settings" : { "status" : 1, "weight" : "0", "settings" : [] },
        "os2intra_global_search_index_section_alter_settings" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "user:name" : true,
              "user:field_name_first" : true,
              "user:field_name_last" : true,
              "node:title" : true,
              "node:field_os2web_base_field_intro" : true,
              "taxonomy_term:name" : true,
              "taxonomy_term:description" : true,
              "node:body:value" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_title" : true,
              "node:field_os2intra_base_structure:name" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_text:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "user:name" : true,
              "user:field_name_first" : true,
              "user:field_name_last" : true,
              "node:title" : true,
              "node:field_os2web_base_field_intro" : true,
              "taxonomy_term:name" : true,
              "taxonomy_term:description" : true,
              "node:body:value" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_title" : true,
              "node:field_os2intra_base_structure:name" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_text:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "user:name" : true,
              "user:field_name_first" : true,
              "user:field_name_last" : true,
              "node:title" : true,
              "node:field_os2web_base_field_intro" : true,
              "taxonomy_term:name" : true,
              "taxonomy_term:description" : true,
              "node:body:value" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_title" : true,
              "node:field_os2intra_base_structure:name" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_text:value" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "user:name" : true,
              "user:field_name_first" : true,
              "user:field_name_last" : true,
              "node:title" : true,
              "node:field_os2web_base_field_intro" : true,
              "taxonomy_term:name" : true,
              "taxonomy_term:description" : true,
              "node:body:value" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_title" : true,
              "node:field_os2intra_base_structure:name" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_text:value" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "user:name" : true,
              "user:field_name_first" : true,
              "user:field_name_last" : true,
              "node:title" : true,
              "node:field_os2web_base_field_intro" : true,
              "taxonomy_term:name" : true,
              "taxonomy_term:description" : true,
              "node:body:value" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_title" : true,
              "node:field_os2intra_base_structure:name" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_text:value" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_elasticsearch_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "125",
            "excerpt_fragments" : "3",
            "concatenator" : "...",
            "highlight" : "never"
          }
        },
        "search_api_elasticsearch_prefix_search" : {
          "status" : 0,
          "weight" : "35",
          "settings" : { "fields" : {
              "user:name" : true,
              "user:field_name_first" : true,
              "user:field_name_last" : true,
              "node:title" : true,
              "node:field_os2web_base_field_intro" : true,
              "taxonomy_term:name" : true,
              "taxonomy_term:description" : true,
              "node:body:value" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_title" : true,
              "node:field_os2intra_base_structure:name" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_text:value" : true
            }
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : {
              "user:name" : true,
              "user:field_name_first" : true,
              "user:field_name_last" : true,
              "node:title" : true,
              "node:field_os2web_base_field_intro" : true,
              "taxonomy_term:name" : true,
              "taxonomy_term:description" : true,
              "node:body:value" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_title" : true,
              "node:field_os2intra_base_structure:name" : true,
              "node:field_os2intra_paragraph:field_os2intra_paragraph_text:value" : true
            },
            "exceptions" : "texan=texa"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "40",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}
