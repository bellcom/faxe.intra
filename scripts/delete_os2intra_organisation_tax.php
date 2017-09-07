<?php

$vocab = taxonomy_vocabulary_machine_name_load('os2intra_organisation_tax');
$terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocab->vid));
foreach ($terms as $term) {
    If ($term->tid == 13943) continue;
  taxonomy_term_delete($term->tid);
}