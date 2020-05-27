<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
$node = node_load(6219);
$node = node_load(5031);
$node = node_load(4345);
$vocab = taxonomy_vocabulary_load(variable_get('os2intra_groups_vocabulary_vid'));
  $tree = taxonomy_get_tree($vocab->vid);

  // find first term with no parents
  // used as default parent tid later
  foreach ($tree as $term) {
    if ($term->parents[0] == 0) {
      $default_parent_tid = $term->tid;
          break;
    }
  }
  var_dump($default_parent_tid);
 $terms=array();
 if ($node->type = 'os2intra_org_group_unit') {
    if (isset($node->field_os2intra_organisation)) {
      $organisation_term_tid = $node->field_os2intra_organisation['und'][0]['target_id'];
      $parent_terms = taxonomy_get_parents_all($organisation_term_tid);
      
      foreach($parent_terms as $parent) {
        if ($parent->tid == $default_parent_tid) {
          //this is top parent term
          break;
        }
        $top_parent_term =$parent;
      }
      $terms[]=$top_parent_term->tid;
    
      }
    }
    else {
    
if (isset($node->og_group_ref) && !empty($node->og_group_ref['und'])) {
  foreach($node->og_group_ref['und']  as $value) {
    $group_node = node_load($value['target_id']);
    if (isset($group_node->field_os2intra_organisation)) {
      $organisation_term_tid = $group_node->field_os2intra_organisation['und'][0]['target_id'];
      $parent_terms = taxonomy_get_parents_all($organisation_term_tid);
      
      foreach($parent_terms as $parent) {
        if ($parent->tid == $default_parent_tid) {
          //this is top parent term
          break;
        }
        $top_parent_term =$parent;
      }
      $terms[]=$top_parent_term->tid;
    
      }
    }
  }  
}  
    var_dump(array_unique($terms));
  
  
$user = user_load(bbbb);
$terms = array();
///var_dump($user);
if (isset($user->og_user_node2) && !empty($user->og_user_node2['und'])) {
foreach($user->og_user_node2['und']  as $value) {
  $group_node = node_load($value['target_id']);

    if (isset($group_node->field_os2intra_organisation)) {
      $organisation_term_tid = $group_node->field_os2intra_organisation['und'][0]['target_id'];

      $parent_terms = taxonomy_get_parents_all($organisation_term_tid);
      
      foreach($parent_terms as $parent) {
        if ($parent->tid == $default_parent_tid) {
          //this is top parent term
          break;
        }
        $top_parent_term =$parent;
      }
      $terms[]=$top_parent_term->tid;
}
}
}
var_dump($terms);
//top parent term has no parents so find it out by checking if it has parents

/*$node->field_os2intra_base_structure['und'][0]['tid'];
var_dump($term_tid);

$parent_terms = taxonomy_get_parents_all($term_tid);

//top parent term has no parents so find it out by checking if it has parents
foreach($parent_terms as $parent) {
  $parent_parents = taxonomy_get_parents_all($parent->tid);
  if ($parent_parents != false) {
    //this is top parent term
    $top_parent_term = $parent;
  }
}
var_dump($top_parent_term);*/