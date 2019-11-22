<?php

/**
 * @file
 * faxe_furniture_stock.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function faxe_furniture_stock_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__webshop-product';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Webshop product',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'webshop-product',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'faxe_furniture_product' => 'faxe_furniture_product',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'content-with-right-sidebar';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'd636802a-6871-41c0-969c-64242d2b28c8';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__webshop-product';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1be22f35-56be-4f8c-8f41-f70eb9c30028';
  $pane->panel = 'content';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1be22f35-56be-4f8c-8f41-f70eb9c30028';
  $display->content['new-1be22f35-56be-4f8c-8f41-f70eb9c30028'] = $pane;
  $display->panels['content'][0] = 'new-1be22f35-56be-4f8c-8f41-f70eb9c30028';
  $pane = new stdClass();
  $pane->pid = 'new-70c1a92e-b7ae-4f6d-b335-b833e2233682';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'faxe_basic_cart-faxe_webshop_shopping_cart';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '70c1a92e-b7ae-4f6d-b335-b833e2233682';
  $display->content['new-70c1a92e-b7ae-4f6d-b335-b833e2233682'] = $pane;
  $display->panels['sidebar'][0] = 'new-70c1a92e-b7ae-4f6d-b335-b833e2233682';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__webshop-product'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function faxe_furniture_stock_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'faxe_webshop';
  $page->task = 'page';
  $page->admin_title = 'Webshop';
  $page->admin_description = '';
  $page->path = 'webshop';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Faxe webshop',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_faxe_webshop__panel';
  $handler->task = 'page';
  $handler->subtask = 'faxe_webshop';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'content-with-right-sidebar';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '531a1786-14aa-4b2a-9fc7-4c2735fb6476';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_faxe_webshop__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a27596cd-516d-4ba0-9cf5-77a181bef119';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'faxe_intra_furniture_stock-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a27596cd-516d-4ba0-9cf5-77a181bef119';
  $display->content['new-a27596cd-516d-4ba0-9cf5-77a181bef119'] = $pane;
  $display->panels['content'][0] = 'new-a27596cd-516d-4ba0-9cf5-77a181bef119';
  $pane = new stdClass();
  $pane->pid = 'new-f0fdf281-bf20-4264-bce0-0dcab4471204';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'faxe_basic_cart-faxe_webshop_shopping_cart';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f0fdf281-bf20-4264-bce0-0dcab4471204';
  $display->content['new-f0fdf281-bf20-4264-bce0-0dcab4471204'] = $pane;
  $display->panels['sidebar'][0] = 'new-f0fdf281-bf20-4264-bce0-0dcab4471204';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['faxe_webshop'] = $page;

  return $pages;

}
