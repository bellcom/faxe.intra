<?php if ($view_mode == 'list'): ?>
  <!-- node--os2intra_org_group_unit--list.tpl.php -->
  <!-- Begin - list -->
  <section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> os2-node-list os2-node-list-group os2-node-list-group-org"<?php print $attributes; ?>>

    <!-- Begin - heading -->
    <div class="os2-node-list-heading">
      <h3 class="os2-node-list-heading-title"><i class="icon fa fa-sitemap"></i>  <a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
    </div>
    <!-- End - heading -->

  </section>
  <!-- End - list -->

<?php endif; ?>
