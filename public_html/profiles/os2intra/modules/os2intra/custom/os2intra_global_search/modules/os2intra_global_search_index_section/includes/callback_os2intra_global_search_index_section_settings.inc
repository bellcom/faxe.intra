<?php
/**
 * @file
 * Search API data alteration callback.
 */

class SearchApiAlterAddSectionAlterSettings extends SearchApiAbstractAlterCallback {

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    foreach ($items as $id => $item) {
      if ($item->node) {
        $node = &$item->node;
      } else {
        $node = &$item;
      }
      if (!$node->nid) {
        continue;
      }
  if (isset($node->field_os2intra_base_structure) && is_array($node->field_os2intra_base_structure['und'])) {
    $term_tid = $node->field_os2intra_base_structure['und'][0]['tid'];
    $parent_terms = taxonomy_get_parents_all($term_tid);

    //top parent term has no parents so find it out by checking if it has parents
    foreach($parent_terms as $parent) {
      $parent_parents = taxonomy_get_parents_all($parent->tid);
      if ($parent_parents != false) {
        //this is top parent term
        $top_parent_term = $parent;
      }
    }
     $item->os2intra_global_search_index_section = $top_parent_term->tid; 
    } 
  
     
    
    }   

  }
   /**
   * {@inheritdoc}
   */
  public function propertyInfo() {
    $ret = array();

    $ret['os2intra_global_search_index_section'] = array(
      'label' => 'os2intra global search section',
      'description' => '',
      'type' => 'text',
    );

    return $ret;
  }
}