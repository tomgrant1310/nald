﻿(function(e){e(function(){e.fn.megadrupalTreeMenu=function(){var t=e(this);not=e("li",t).has("div.dropzone");e("li",t).not(not).prepend('<div class="dropzone"></div>');e("dl, .dropzone",t).droppable({accept:"li.dragitem",tolerance:"pointer",drop:function(n,r){var i=e(this).parent();var s=!e(this).hasClass("dropzone");if(s&&i.children("ul").length==0){i.append("<ul/>")}if(s){i.addClass("sm2_liOpen").removeClass("sm2_liClosed").children("ul").append(r.draggable)}else{i.before(r.draggable)}e("li.sm2_liOpen",t).not(":has(li:not(.ui-draggable-dragging))").removeClass("sm2_liOpen");i.find("dl,.dropzone").css({backgroundColor:"",borderColor:""})},over:function(){e(this).filter("dl").css({backgroundColor:"#F90"});e(this).filter(".dropzone").css({borderColor:"#F90"})},out:function(){e(this).filter("dl").css({backgroundColor:""});e(this).filter(".dropzone").css({borderColor:""})}});e("li",t).draggable({handle:" > dl",opacity:.8,addClasses:false,helper:"clone",zIndex:100})};e("#dropdown").megadrupalTreeMenu();e("#dropdown dl").live("mouseenter",function(){e(this).addClass("hover")}).live("mouseleave",function(){e(this).removeClass("hover")});e("#btn_add").click(function(){e("#dropdown").append(e("#dropdown li:last").clone());e("#dropdown").megadrupalTreeMenu()})})})(jQuery)