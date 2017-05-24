(function($) {

	(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/da_DK/sdk.js#xfbml=1&version=v2.5&appId=349377909301";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));


  var url = $('.fb-page').data('refresh');
   
  $('.fb-page').load(url, { width: $('#fb-root').width() },
  function() {
     FB.XFBML.parse(document.getElementById('.fb-page'),
     function() {
        $('.fb-page').fadeIn("slow");
     });
  });
}(jQuery));;
(function ($) {

  Drupal.behaviors.os2web_intra_user_menu = {
    attach: function (context, settings) {
      os2web_intra_user_menu_groups();
    }
  };

  /**
   * Fetches user group memberships from ajax callback.
   */
  function os2web_intra_user_menu_groups() {

    $.getJSON('/user-menu/ajax', function(data) {

      // Test if we got group data back
      if (Object.keys(data).length > 0) {

        var $ul = $('<ul class="main-navigation-list-dropdown-menu sidebar-navigation-dropdown-menu">');

        // Generate list with links and append to parent menu item.
        for (var key in data) {
          var li = $('<li class="main-navigation-list-link sidebar-navigation-link"><a href="/node/' + data[key].nid + '">' + data[key].title + '</a></li>');
          $ul.append(li);
        }
      }
      var $menu_item = $('.group-menu-item').parent();

      if ($ul) {
        $menu_item.append($ul);

        // Set class on 'ul's parent
        $menu_item
            .removeClass('main-navigation-list-link')
            .addClass('main-navigation-list-dropdown');
      }

      $('.user-group.sidebar-navigation-link')
          .removeClass('sidebar-navigation-link')
          .addClass('expanded sidebar-navigation-dropdown');
    });
  }

}(jQuery));
;
