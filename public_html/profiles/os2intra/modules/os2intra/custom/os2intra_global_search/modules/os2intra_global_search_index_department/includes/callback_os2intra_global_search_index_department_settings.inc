<?php
/**
 * @file
 * Search API data alteration callback.
 */

class SearchApiAlterAddDepartmentAlterSettings extends SearchApiAbstractAlterCallback {

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    foreach ($items as $id => $item) {
      $terms = array();  
      $default_parent_id = $this->options['os2intra_organisation_taxonomy_top_term_tid'];
      switch ($item->item_type) {
        case 'node' :
          $node = $item->node;
          if ($node->type == 'os2intra_org_group_unit') {
            $tid = $node->field_os2intra_organisation['und'][0]['target_id'];
            $terms[] = _os2intra_global_search_index_department_get_parent_tid($tid, $default_parent_id);
          }
          else {
            if (isset($node->og_group_ref) && !empty($node->og_group_ref['und'])) {
              foreach($node->og_group_ref['und']  as $value) {
                $group_node = node_load($value['target_id']);
                if (isset($group_node->field_os2intra_organisation)) {
                  $tid = $group_node->field_os2intra_organisation['und'][0]['target_id'];
                  $terms[] = _os2intra_global_search_index_department_get_parent_tid($tid, $default_parent_id);
                }  
              }
            }
          }          
          $terms = array_unique($terms);
          $item->os2intra_global_search_index_department = implode(' ', $terms);
          break;
        case 'user' :
          $user = $item->user;
          if (isset($user->og_user_node2) && !empty($user->og_user_node2['und'])) {
            foreach($user->og_user_node2['und']  as $value) {
              $group_node = node_load($value['target_id']);

              if (isset($group_node->field_os2intra_organisation)) {
                $tid = $group_node->field_os2intra_organisation['und'][0]['target_id'];
                $terms[] = _os2intra_global_search_index_department_get_parent_tid($tid, $default_parent_id);
              }
            }
          }  
          $terms = array_unique($terms);
          $item->os2intra_global_search_index_department = implode(' ', $terms);
          break;
        case 'taxonomy_term':
          $term = $item->taxonomy_term;
          $terms[] = _os2intra_global_search_index_department_get_parent_tid($term->tid, $default_parent_id);
          $terms = array_unique($terms);
          $item->os2intra_global_search_index_department = implode(' ', $terms);

          break;
      }
    }       

  }
  
   /**
   * {@inheritdoc}
   */
  public function configurationForm() {
    $parent_form = parent::configurationForm();
    
    $parent_form['os2intra_organisation_taxonomy_top_term_tid'] = array(
      '#type' => 'textfield',
      '#title' => t('term ID of top level taxonomy term in OS2intra organisation taxonomy'),
      '#default_value' => isset($this->options['os2intra_organisation_taxonomy_top_term_tid']) ? $this->options['os2intra_organisation_taxonomy_top_term_tid'] : false,
      '#size' => 10,
      '#required' => true,
    );

    return $parent_form;
  }
  
   /**
   * {@inheritdoc}
   */
  public function propertyInfo() {
    $ret = array();

    $ret['os2intra_global_search_index_department'] = array(
      'label' => 'os2intra global search department',
      'description' => '',
      'type' => 'text',
    );

    return $ret;
  }
}

