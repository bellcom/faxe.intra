<!-- content-with-left-and-right-sidebar.tpl.php -->
<div class="row" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['sidebar-left']): ?>
    <!-- Begin - left sidebar -->
    <div class="col-md-3">
      <?php print $content['sidebar-left']; ?>
    </div>
    <!-- End - left sidebar -->
  <?php endif ?>

  <?php if ($content['sidebar-right']): ?>
    <!-- Begin - right sidebar -->
    <div class="col-md-3 col-md-push-6 hidden-print">
      <?php print $content['sidebar-right']; ?>
    </div>
    <!-- End - right sidebar -->
  <?php endif ?>

  <?php if ($content['content']): ?>

    <?php if ($content['sidebar-left'] && $content['sidebar-right']): ?>
      <!-- Begin - content -->
      <div class="col-md-6 col-md-pull-3">
        <?php print $content['content']; ?>
      </div>
      <!-- End - content -->

    <?php elseif (!$content['sidebar-left'] && !$content['sidebar-right']): ?>
      <!-- Begin - content -->
      <div class="col-md-12">
        <?php print $content['content']; ?>
      </div>
      <!-- End - content -->

    <?php else: ?>
      <!-- Begin - content -->
      <div class="col-md-9">
        <?php print $content['content']; ?>
      </div>
      <!-- End - content -->

    <?php endif ?>

  <?php endif ?>

</div>
