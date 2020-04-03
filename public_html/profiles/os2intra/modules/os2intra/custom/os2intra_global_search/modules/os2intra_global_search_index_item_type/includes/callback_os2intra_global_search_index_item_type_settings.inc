<?php
/**
 * @file
 * Search API data alteration callback.
 */

class SearchApiAlterAddItemTypeAlterSettings extends SearchApiAbstractAlterCallback {

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    foreach ($items as $id => $item) {
      switch ($item->item_type) {
        case 'node' :
          if ($item->node->type == 'os2intra_org_group_unit') {
            $item->os2intra_global_search_index_item_type = 'Afdeling';
          }
          else {
            $item->os2intra_global_search_index_item_type = 'Indhold';
          }
          break;
        case 'user' :
          $item->os2intra_global_search_index_item_type = 'Person';
          break;
        case 'taxonomy_term':
          if ($item->taxonomy_term->vocabulary_machine_name == 'os2web_base_tax_site_structure') {
            $item->os2intra_global_search_index_item_type = 'Sektioner';
          }
          if ($item->taxonomy_term->vocabulary_machine_name == 'os2intra_organisation_tax') {
            $item->os2intra_global_search_index_item_type = 'Afdeling';
          }
          break;
      }
    }    
  
  }
   /**
   * {@inheritdoc}
   */
  public function propertyInfo() {
    $ret = array();

    $ret['os2intra_global_search_index_item_type'] = array(
      'label' => 'os2intra global search item type',
      'description' => '',
      'type' => 'text',
    );

    return $ret;
  }
}