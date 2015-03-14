(function ($) {
Drupal.behaviors.md_magnum = {
	attach: function () {
			$('#edit-logo').appendTo($('#edit-favicon-webclip > .fieldset-wrapper'));
			$('#edit-favicon').appendTo($('#edit-favicon-webclip > .fieldset-wrapper'));
			$('.form-item-css3-textarea').before($('#edit-theme-settings'));
			$('#edit-skins, #edit-choose-ft-pattern, #edit-Backgroundop-blocks, #edit-sidebar-position, #edit-bottom-blocks, #edit-node-article-display, #edit-node-photo-display, #edit-node-video-display').removeClass('form-select');
	}
};
Drupal.behaviors.myBehavior = {
    attach: function (context, settings) {
        //code starts


        //code ends
    }
};
})(jQuery);

jQuery(function($){

    /*--------------------------- Header -----------------------------------*/

    var headerBackgroundType = $("#edit-design-header .header-background-type").find("option:selected").val();

    changeHeaderBgType($("#edit-design-header"),headerBackgroundType);

    $(".header-background-type").click(function(){
        var headerBackgroundType = $(this).find("option:selected").val();
        var parentDiv = $(this).parent().parent();
        changeHeaderBgType(parentDiv,headerBackgroundType);
    })
    function changeHeaderBgType(obj,headerBackgroundType) {
        if(headerBackgroundType == 'md_fullscreen_slider') {
            obj.find("#header-video-wrapper").hide();
            obj.find("#header-image-wrapper").hide();
            obj.find("#header-content-wrapper").hide();
            $("#edit-footer-background").find("option[value='global']").hide();
            $("#edit-parallax-1-background-type").find("option[value='global']").hide();
            $("#edit-parallax-2-background-type").find("option[value='global']").hide();
            $("#edit-parallax-3-background-type").find("option[value='global']").hide();
        }
        if(headerBackgroundType == 'custom') {
            $("#edit-footer-background").find("option[value='global']").show();
            $("#edit-parallax-1-background-type").find("option[value='global']").show();
            $("#edit-parallax-2-background-type").find("option[value='global']").show();
            $("#edit-parallax-3-background-type").find("option[value='global']").show();
            obj.find("#header-video-wrapper").hide();
            obj.find("#header-image-wrapper").show();
            obj.find("#header-content-wrapper").show();
        }
        if (headerBackgroundType == 'video') {
            $("#edit-footer-background").find("option[value='global']").show();
            $("#edit-parallax-1-background-type").find("option[value='global']").show();
            $("#edit-parallax-2-background-type").find("option[value='global']").show();
            $("#edit-parallax-3-background-type").find("option[value='global']").show();
            obj.find("#header-video-wrapper").show();
            obj.find("#header-image-wrapper").hide();
            obj.find("#header-content-wrapper").hide();
        }
    }
    // Header Size
    jQuery(document).ready(function($) {
        var headerSize = $("#edit-design-header .hdswrap .selected").find(".slitem").attr("id");

        changeHeaderSzType($("#edit-design-header"),headerSize);

        $(".hdswrap .slitem").click(function(){
            var headerSize = $(this).attr("id");
            console.log(headerSize);
            var parentDiv = $(this).parent().parent().parent().parent().parent();
            changeHeaderSzType(parentDiv,headerSize);
        })
    });
    function changeHeaderSzType(obj,headerSize) {
        if(headerSize == 'hdsshort') {
            obj.find(".form-item-header-custom-height").hide();
        }
        if(headerSize == 'hdsfull') {
            obj.find(".form-item-header-custom-height").hide();
        }
        if (headerSize == 'hdscustom') {
            obj.find(".form-item-header-custom-height").show();
        }
    }


    // Video background content display
    jQuery(document).ready(function(){
        var headerVdContentType = $("#edit-design-header #edit-header-video-content-display").find("option:selected").val();

        changeHeaderVdContentType($("#edit-design-header"),headerVdContentType);

        $("#edit-header-video-content-display").click(function(){
            var headerVdContentType = $(this).find("option:selected").val();
            var parentDiv = $(this).parent().parent();
            changeHeaderVdContentType(parentDiv,headerVdContentType);
        })
    })
    function changeHeaderVdContentType(obj,headerVdContentType) {
        if(headerVdContentType == '1') {
            obj.find("#hd-vd-ct-dp-2").hide();
            obj.find("#hd-vd-ct-dp-1").show();
        }
        if (headerVdContentType == '2') {
            obj.find("#hd-vd-ct-dp-2").show();
            obj.find("#hd-vd-ct-dp-1").hide();
        }
    }

    jQuery(document).ready(function($) {
        var headerContentType = $("#edit-design-header .hdctwrap .selected").find(".slitem").attr("id");
        changeHeaderContentType($("#edit-design-header"),headerContentType);
        $(".hdctwrap .slitem").click(function(){
            var headerContentType = $(this).attr("id");
            var parentDiv = $(this).parent().parent().parent().parent().parent();
            changeHeaderContentType(parentDiv,headerContentType);
        })
    });
    function changeHeaderContentType(obj,headerContentType) {
        if(headerContentType == 'hdcttext') {
            obj.find("#header-text-display").show();
            obj.find("#header-text-icon-display").hide();

        }
        if (headerContentType == 'hdcttext_icon') {

            obj.find("#header-text-display").hide();
            obj.find("#header-text-icon-display").show();
        }
    }
    // Define default value header text & icon display

    /*--------------------------------------------- Footer --------------------------------------------*/
    var footerBackgroundType = $("#edit-design-footer #edit-footer-background").find("option:selected").val();

    changefooterBgType($("#edit-design-footer"),footerBackgroundType);

    $("#edit-design-footer #edit-footer-background").click(function(){
        var footerBackgroundType = $(this).find("option:selected").val();
        var parentDiv = $(this).parent().parent();
        changefooterBgType(parentDiv,footerBackgroundType);
    })
    function changefooterBgType(obj,footerBackgroundType) {
        if(footerBackgroundType == 'global') {
            obj.find(".form-item-footer-content-display").hide();
            obj.find("#footer-custom-background").hide();
            obj.find(".form-item-footer-social-text").show();
            obj.find("#ft-pattern-bg").hide();
            obj.find("#ft-color-bg").hide();
        }
        if(footerBackgroundType == 'custom') {
            obj.find(".form-item-footer-content-display").show();
            obj.find("#ft-video-bg").hide();
            obj.find("#footer-custom-image").show();
            obj.find("#footer-custom-background").show();
            obj.find(".form-item-footer-social-text").hide();
            obj.find("#ft-pattern-bg").hide();
            obj.find("#ft-color-bg").hide();
        }
        if (footerBackgroundType == 'video') {
            obj.find(".form-item-footer-content-display").show();
            obj.find("#footer-custom-background").show();
            obj.find("#ft-video-bg").show();
            obj.find("#footer-custom-image").hide();
            obj.find(".form-item-footer-social-text").hide();
            obj.find("#ft-pattern-bg").hide();
            obj.find("#ft-color-bg").hide();
        }
        if (footerBackgroundType == 'pattern') {
            obj.find(".form-item-footer-content-display").show();
            obj.find("#footer-custom-background").hide();
            obj.find("#ft-video-bg").hide();
            obj.find("#footer-custom-image").hide();
            obj.find(".form-item-footer-social-text").hide();
            obj.find("#ft-pattern-bg").show();
            obj.find("#ft-color-bg").hide();
        }
        if (footerBackgroundType == 'color') {
            obj.find(".form-item-footer-content-display").show();
            obj.find("#footer-custom-background").hide();
            obj.find("#ft-video-bg").hide();
            obj.find("#footer-custom-image").hide();
            obj.find(".form-item-footer-social-text").hide();
            obj.find("#ft-pattern-bg").hide();
            obj.find("#ft-color-bg").show();
        }
    }



    /*--------------------------------------------- Parallax --------------------------------------------*/
    // Enable parallax
    $('.enable-parallax').bind('change', function() {
        if ($(this).is(':checked')) {
            $(this).parent().next().show();
        } else {
            $(this).parent().next().hide();
        }
    });
    $('.enable-parallax').trigger('change');
    //Choose parallax Background type
    var parallaxContentType1 = $("#parallax-1-custom .parallax-content-type").find("option:selected").val();
    var parallaxContentType2 = $("#parallax-2-custom .parallax-content-type").find("option:selected").val();
    var parallaxContentType3 = $("#parallax-3-custom .parallax-content-type").find("option:selected").val();
    changeParallax($("#parallax-1-custom"),parallaxContentType1);
    changeParallax($("#parallax-2-custom"),parallaxContentType2);
    changeParallax($("#parallax-3-custom"),parallaxContentType3);
    $(".parallax-content-type").click(function(){
        var parallaxContentType = $(this).find("option:selected").val();
        var parentDiv = $(this).parent().parent();
        changeParallax(parentDiv,parallaxContentType);
    })
    function changeParallax(obj,parallaxContentType) {

        if(parallaxContentType == 'text') {
            obj.find(".pr-ct-text-wrapper").show();
            obj.find(".pr-text-link-display").hide();
        }
        if (parallaxContentType == 'text_link') {
            obj.find(".pr-ct-text-wrapper").hide();
            obj.find(".pr-text-link-display").show();
        }

    }
    var parallaxBackgroundType1 = $("#parallax-1-custom .pr-background-type").find("option:selected").val();
    var parallaxBackgroundType2 = $("#parallax-2-custom .pr-background-type").find("option:selected").val();
    var parallaxBackgroundType3 = $("#parallax-3-custom .pr-background-type").find("option:selected").val();
    changeParallaxBgType($("#parallax-1-custom"),parallaxBackgroundType1);
    changeParallaxBgType($("#parallax-2-custom"),parallaxBackgroundType2);
    changeParallaxBgType($("#parallax-3-custom"),parallaxBackgroundType3);
    $(".pr-background-type").click(function(){
        var parallaxBackgroundType = $(this).find("option:selected").val();
        var parentDiv = $(this).parent().parent();
        changeParallaxBgType(parentDiv,parallaxBackgroundType);
    })
    function changeParallaxBgType(obj,parallaxBackgroundType) {
        if(parallaxBackgroundType == 'global') {
            obj.find("#custom-bg-wrapper").hide();
            obj.find("#custom-video-wrapper").hide();
            obj.find(".pr-pattern-bg").hide();
            obj.find(".pr-color-bg").hide();
        }
        if (parallaxBackgroundType == 'custom') {
            obj.find("#custom-bg-wrapper").show();
            obj.find("#custom-video-wrapper").hide();
            obj.find(".pr-pattern-bg").hide();
            obj.find(".pr-color-bg").hide();
        }
        if (parallaxBackgroundType == 'video') {
            obj.find("#custom-bg-wrapper").hide();
            obj.find("#custom-video-wrapper").show();
            obj.find(".pr-pattern-bg").hide();
            obj.find(".pr-color-bg").hide();
        }
        if (parallaxBackgroundType == 'pattern') {
            obj.find("#custom-bg-wrapper").hide();
            obj.find("#custom-video-wrapper").hide();
            obj.find(".pr-pattern-bg").show();
            obj.find(".pr-color-bg").hide();
        }
        if (parallaxBackgroundType == 'color') {
            obj.find("#custom-bg-wrapper").hide();
            obj.find("#custom-video-wrapper").hide();
            obj.find(".pr-pattern-bg").hide();
            obj.find(".pr-color-bg").show();
        }

    }
    // Parallax Size
    jQuery(document).ready(function($) {
        var pr1Size = $("#parallax-1-custom .pr1swrap .selected").find(".slitem").attr("id");
        var pr2Size = $("#parallax-2-custom .pr2swrap .selected").find(".slitem").attr("id");
        var pr3Size = $("#parallax-3-custom .pr3swrap .selected").find(".slitem").attr("id");

        changePrSzType(1,$("#parallax-1-custom"),pr1Size);
        changePrSzType(2,$("#parallax-2-custom"),pr2Size);
        changePrSzType(3,$("#parallax-3-custom"),pr3Size);

        $(".pr1swrap .slitem").click(function(){
            var pr1Size = $(this).attr("id");
            var parentDiv = $(this).parent().parent().parent().parent().parent();
            changePrSzType(1,parentDiv,pr1Size);
        })
        $(".pr2swrap .slitem").click(function(){
            var pr2Size = $(this).attr("id");
            var parentDiv = $(this).parent().parent().parent().parent().parent();
            changePrSzType(2,parentDiv,pr2Size);
        })
        $(".pr3swrap .slitem").click(function(){
            var pr3Size = $(this).attr("id");
            var parentDiv = $(this).parent().parent().parent().parent().parent();
            changePrSzType(3,parentDiv,pr3Size);
        })
    });
    function changePrSzType(prNum,obj,prSize) {
        if(prSize == 'pr'+prNum+'ssmall') {
            obj.find(".pr-size").hide();
        }
        if(prSize == 'pr'+prNum+'smedium') {
            obj.find(".pr-size").hide();
        }
        if(prSize == 'pr'+prNum+'sbig') {
            obj.find(".pr-size").hide();
        }
        if (prSize == 'pr'+prNum+'scustom') {
            obj.find(".pr-size").show();
        }
    }

    /*-------------------------- 404 Page -----------------------------*/

    jQuery(document).ready(function(){
        var nfBackgroundType = $("#edit-design-nf #edit-nf-background").find("option:selected").val();

        changenfBgType($("#edit-design-nf"),nfBackgroundType);

        $("#edit-design-nf #edit-nf-background").click(function(){
            var nfBackgroundType = $(this).find("option:selected").val();
            var parentDiv = $(this).parent().parent();
            changenfBgType(parentDiv,nfBackgroundType);
        })
        function changenfBgType(obj,nfBackgroundType) {
            if(nfBackgroundType == 'custom') {
                obj.find("#nf-video-bg").hide();
                obj.find("#nf-custom-image").show();
            }
            if (nfBackgroundType == 'video') {
                obj.find("#nf-video-bg").show();
                obj.find("#nf-custom-image").hide();
            }
        }


        var nfRmSlideButton = '<input id="nf-remove-slide" class="form-submit remove-button remove-slide" type="button" value="Remove image">';
        // Add remove button
        $(".nf-image-custom").each(function(i,obj) {
            $(this).after(nfRmSlideButton);
        })
        var arrnfSid = new Array();

        $(".nf-slider-wrapper .nf-image-custom").each(function(e,obj){
            var nfSid = parseInt($(this).attr("nf-id"),10);
            arrnfSid.push(nfSid);
            $(this).after('<input id="nf-slide-hidden-'+nfSid+'" type="hidden" value="'+nfSid+'" name="nf_slide_hidden_'+nfSid+'">');
            filestyle("#edit-nf-image-upload-"+nfSid+"", 'form-item-files-nf-image-upload-'+nfSid+'', '.form-item-nf-image-path-'+nfSid+'');
        });
        console.log(arrnfSid);
        var maxnfSid = Math.max.apply(Math, arrnfSid);
        $("#nf-slide-num").val(maxnfSid);
        var numnfSid = arrnfSid.length;
        if(numnfSid <=1 ){
            $(".nf-slider-wrapper #nf-remove-slide").hide();
            $("#nf-slide-effect").hide();
        }
        nfRmSlide();
    });
    function getnfSlideMarkup (newnfSid) {
        var newSlide = '<div id="nf-image-custom-'+newnfSid+'" class="clearfix nf-image-custom" nf-id="'+newnfSid+'">'
            +'<div class="form-item form-type-textfield form-item-nf-image-path-'+newnfSid+'">'
            +'<label for="edit-nf-image-path">Path to custom background image </label>'
            +'<input id="edit-nf-image-path-'+newnfSid+'" class="form-text" type="text" maxlength="255" size="60" value="" name="nf_image_path_'+newnfSid+'">'
            +'<div class="filewrapper btn-upload">'
            +'<input id="edit-nf-image-upload-'+newnfSid+'" class="form-file" type="file" size="60" name="files[nf_image_upload_'+newnfSid+']" style="opacity: 0;">'
            +'<div class="filetext">'
            +'<span></span>'
            +'Upload a file'
            +'</div>'
            +'</div>'
            +'</div>'
            +'<div class="form-item form-type-file form-item-files-nf-image-upload-'+newnfSid+'"> </div>'
            +'</div>'
            +'<input id="nf-slide-hidden-'+newnfSid+'" type="hidden" name="nf_slide_hidden_'+newnfSid+'" value="'+newnfSid+'">'
            +'<input id="nf-remove-slide" class="form-submit remove-button remove-slide" type="button" value="Remove image">';
        return newSlide;
    }

    $(".nf-add-more-slide").click(function(){
        var arrnfid = new Array();
        $(this).parent().find(".nf-image-custom").each(function(){
            var nfID = parseInt($(this).attr("nf-id"),10);
            arrnfid.push(nfID);
        });
        var maxSdID = parseInt($(this).prev().val(),10);
        var newNumSdID = maxSdID+1;
        var newMarkUp = getnfSlideMarkup (newNumSdID);
        $(this).parent().find(".nf-slider-wrapper .fieldset-wrapper").append(newMarkUp);
        $(this).parent().find(".nf-slider-wrapper .fieldset-wrapper #nf-remove-slide").show();
        $(this).parent().parent().parent().find("#nf-slide-effect").show();
        arrnfid.push(newNumSdID);
        console.log(arrnfid);
        var newMaxSdID = Math.max.apply(Math, arrnfid);
        $(this).prev().val(newMaxSdID);
        jQuery(document).ready(function(){
            filestyle("#edit-nf-image-upload-"+newNumSdID+"", 'form-item-files-nf-image-upload-'+newNumSdID+'', '.form-item-nf-image-path-'+newNumSdID+'');
        })
        nfRmSlide();
    });
    function nfRmSlide() {
        $(".remove-slide").click(function(){
            var arrNfID = new Array();
            $(this).parent().find(".nf-image-custom").each(function(){
                var nfID = parseInt($(this).attr("nf-id"),10);
                arrNfID.push(nfID);
            })

            var img = $(this).prev().prev();
            var hidden = $(this).prev();
            arrNfID = jQuery.grep(arrNfID, function(value) {
                return value != parseInt(img.attr("nf-id"),10);
            });
            console.log(arrNfID);
            var maxNfID = Math.max.apply(Math, arrNfID);
            $(this).parent().parent().parent().parent().find(".nf-slide-num").val(maxNfID);
            if(arrNfID.length <=1 ){
                $(this).parent().find(".remove-slide").hide();
                $(this).parent().parent().parent().parent().find("#nf-slide-effect").hide();
            }
            $(this).remove();
            $(img).remove();
            $(hidden).remove();

        })
    }
    /*----------------------------------------------- Team Setting ---------------------------------------------------------*/
    jQuery(document).ready(function($){
        if($('#edit-enable-team-header').is(':checked')) {
            $('#team-header').show();
        } else {
            $('#team-header').hide();
        };
        if($('#edit-preloader-enable-logo').is(':checked')) {
            $('.form-item-preloader-logo-path').show();
        } else {
            $('.form-item-preloader-logo-path').hide();
        };
        if($('#edit-menu-sticky').is(':checked')) {
            $('#menu-custom').show();
        } else {
            $('#menu-custom').hide();
        }
        $('#edit-enable-team-header').bind('change', function() {
            if ($(this).is(':checked')) {
                $('#team-header').show();
            } else {
                $('#team-header').hide();
            }
        });
        $('#edit-preloader-enable-logo').bind('change', function() {
            if ($(this).is(':checked')) {
                $('.form-item-preloader-logo-path').show();
            } else {
                $('.form-item-preloader-logo-path').hide();
            }
        });
        $('#edit-menu-sticky').bind('change', function() {
            if ($(this).is(':checked')) {
                $('#menu-custom').show();
            } else {
                $('#menu-custom').hide();
            }
        });

        $('#edit-enable-team-header','#edit-preloader-enable-logo','#edit-menu-sticky').trigger('change');
    })

    // Color picker
	var colorpickerHTML = '<span class="colorSelect"><span></span></span>';


	$(".md-listleft a").click(function(){
		$(this).parent().parent().find("a").removeClass("border-white");
		$(this).parent().prev().find("a").addClass("border-white")
	});
	
	// Fonts
	$(".choosefont").choosefont();
	// Cookies Tabs
	$("#md-general-settings, #md-design, #md-text-typography, #md-pages, #md-nodes, #md-display, #md-custom-code, #md-tabs, #md-subtabs, #md-config").tabs({
		cookie: {
				expires: 1
		}
	});
	
	$(".md-listleft li.ui-state-active").each(function(){
		$(this).prev().find("a").addClass("border-white");
	});

	// Color picker
	$('.form-colorpicker').before(colorpickerHTML);
	$('.colorSelect').each(function(){
		tmpbackground = $(this).next().val();
		$(this).css({'background-color':"#"+tmpbackground});
	});
	$('span.colorSelect').ColorPicker({
			onSubmit: function(hsb, hex, rgb, el) {
				$(el).css({'background-color':"#"+hex});
				$(el).next().val(hex);
				$(el).ColorPickerHide();
			},
			onBeforeShow: function () {
				current_obj = this;
				$(this).ColorPickerSetColor($(this).next().val());
			},
			onChange: function (hsb, hex, rgb) {
				$(current_obj).css({'background-color':"#"+hex});
				$(current_obj).next().val(hex);
			}
		});

	listBackgroundw = $(".md-wrap").width() - 300;
	$(".md-listBackground").width(listBackgroundw);
	
	$('.md-listBackground legend').each(function(){
		tmphtml = $(this).find('span').html();
		$(this).replaceWith('<h3>' + tmphtml + '</h3>');
	});

    /* --------------------- Preloader ---------------------*/
    // Preloader Background Type
    jQuery(document).ready(function($) {
        var preLoadBgType = $("#edit-preloader-bg-type").find("option:selected").val();
        changePreLoadBgType($("#ds-preloader"),preLoadBgType);

        $("#edit-preloader-bg-type").click(function(){
            var preLoadBackgroundType = $(this).find("option:selected").val();
            var parentDiv = $(this).parent().parent();
            changePreLoadBgType(parentDiv,preLoadBackgroundType);
        })
    })

    function changePreLoadBgType(obj,preLoadBackgroundType) {
        if(preLoadBackgroundType == 'skin') {
            obj.find("#preloader-bg-color").hide();
        }
        if (preLoadBackgroundType == 'custom') {
            obj.find("#preloader-bg-color").show();
        }
    }
    fakeselect('#edit-preloader-type', 'pre', 8);

    // Preloader Background color picker
    $('input#edit-preloader-bg-color').before('<span id="backgroundcolorselect" class="colorSelect2"><span></span></span>');
    // End Preloader Settings

    // Menu Settings
    $('input#edit-menu-bg-color').before('<span id="backgroundcolorselect" class="colorSelect2"><span></span></span>');
    $('input#edit-menu-link-color').before('<span id="backgroundcolorselect" class="colorSelect2"><span></span></span>');
    $('input#edit-menu-link-hover-color').before('<span id="backgroundcolorselect" class="colorSelect2"><span></span></span>');
    // End Menu settings

    //Footer Pattern Setting
    fakeselect('#edit-choose-ft-pattern', 'pt', 44);
    // background pattern
    if ($('#edit-ft-bg-color').val()) {
        $('.ptwrap div').css({'background-color': '#' + $('#edit-ft-bg-color').val()})
    }
    // Background color picker
    $('input#edit-ft-bg-color').before('<span id="backgroundcolorselect" class="colorSelect2"><span></span></span>');

    //Parallax background pattern
    fakeselect('#edit-choose-pr1-pattern', 'pr1pt', 20);
    if ($('#edit-pr1-bg-color').val()) {
        $('.pr1ptwrap div').css({'background-color': '#' + $('#edit-pr1-bg-color').val()})
    }
    // Background color picker
    $('input#edit-pr1-bg-color').before('<span id="backgroundcolorselect" class="colorSelect2"><span></span></span>');

    fakeselect('#edit-choose-pr2-pattern', 'pr2pt', 20);
    // background pattern
    if ($('#edit-pr2-bg-color').val()) {
        $('.pr2ptwrap div').css({'background-color': '#' + $('#edit-pr2-bg-color').val()})
    }
    // Background color picker
    $('input#edit-pr2-bg-color').before('<span id="backgroundcolorselect" class="colorSelect2"><span></span></span>');

    fakeselect('#edit-choose-pr3-pattern', 'pr3pt', 20);
    // background pattern
    if ($('#edit-pr3-bg-color').val()) {
        $('.pr3ptwrap div').css({'background-color': '#' + $('#edit-pr3-bg-color').val()})
    }
    // Background color picker
    $('input#edit-pr3-bg-color').before('<span id="backgroundcolorselect" class="colorSelect2"><span></span></span>');

    $('.colorSelect2').each(function(){
        tmpbackground = $(this).next().val();
        $(this).css({'background-color':"#"+tmpbackground});
        $('.ptwrap div').css({'background-color':"#"+tmpbackground});
    });
    $('span.colorSelect2').ColorPicker({
        onSubmit: function(hsb, hex, rgb, el) {
            $(el).css({'background-color':"#"+hex});
            $('.ptwrap div').css({'background-color':"#"+hex});
            $(el).next().val(hex);
            $(el).ColorPickerHide();
        },
        onBeforeShow: function () {
            current_obj = this;
            $(this).ColorPickerSetColor($(this).next().val());
        },
        onChange: function (hsb, hex, rgb) {
            $(current_obj).css({'background-color':"#"+hex});
            $('.ptwrap div').css({'background-color':"#"+hex});
            $(current_obj).next().val(hex);
        }
    });

    fakeselect('#edit-skins', 'sk', 8);
    fakeselect('#edit-parallax-1-size', 'pr1s', 3);
    fakeselect('#edit-parallax-2-size', 'pr2s', 3);
    fakeselect('#edit-parallax-3-size', 'pr3s', 3);
    fakeselect('#edit-header-content-display', 'hdct', 2);
    fakeselect('#edit-header-size', 'hds', 2);
    fakeselect('#edit-sidebar-position', 'sbp', 2);
    fakeselect('#edit-bottom-blocks', 'bb', 6);
    fakeselect('#edit-node-article-display', 'nbd', 6);
    fakeselect('#edit-node-photo-display', 'npd', 4);
    fakeselect('#edit-node-video-display', 'nvd', 4);
	
	// Design: Header
	changetopbl($('#dk_container_edit-ht-type .dk_option_current a').attr('data-dk-dropdown-value'));
	$('#dk_container_edit-ht-type .dk_options_inner a').click(function(){
		changetopbl($(this).attr('data-dk-dropdown-value'));
	});

    // Design: Footer
    inputtoslide("#edit-footer-bo-size", 1, 20);
    // Design: Block
    inputtoslide("#edit-block-title-Background-space", 0, 20);
    inputtoslide("#edit-block-bo-size", 1, 20);

    // Border type:
	$('.form-bordertype label').each(function(){
        $(this).after('<div class="border-type border-type-'+$(this).text()+'"></div>')
    })

    jQuery(document).ready(function($){
        $('.form-item-files-logo-upload').hide();
        $('.form-item-logo-path').hide();
        $('.form-item-files-favicon-upload').hide();
        $('.form-item-favicon-path').hide();
        $('.form-item-css3-textarea').hide();
    });
	filestyle("#edit-logo-normal-upload", '.form-item-files-logo-normal-upload', '.form-item-logo-normal-path');
	filestyle("#edit-fvicon-upload", '.form-item-files-fvicon-upload', '.form-item-fvicon-path');
	filestyle("#edit-webclip-upload", '.form-item-files-webclip-upload', '.form-item-webclip-path');
	filestyle("#edit-bg-upload", '.form-item-files-bg-upload', '.form-item-bg-path');
    filestyle("#edit-restore-file-upload", '.form-item-files-restore-file-upload', '.form-item-restore-file-path');
    filestyle("#edit-logo-retina-upload", '.form-item-files-logo-retina-upload', '.form-item-logo-retina-path');
    filestyle("#edit-footer-logo-upload", '.form-item-files-footer-logo-upload', '.form-item-footer-logo-path');
    filestyle("#edit-preloader-logo-upload", '.form-item-files-preloader-logo-upload', '.form-item-preloader-logo-path');
    filestyle("#edit-sd1-image-upload-1", '.form-item-files-sd1-image-upload-1', '.form-item-sd1-image-path-1');
    filestyle("#edit-sd2-image-upload-1", '.form-item-files-sd2-image-upload-1', '.form-item-sd2-image-path-1');
    filestyle("#edit-sd3-image-upload-1", '.form-item-files-sd3-image-upload-1', '.form-item-sd3-image-path-1');
    filestyle("#edit-nm4-image-upload", '.form-item-files-nm4-image-upload', '.form-item-nm4-image-path');
    filestyle("#edit-nm3-image-upload", '.form-item-files-nm3-image-upload', '.form-item-nm3-image-path');
    filestyle("#edit-nm2-image-upload", '.form-item-files-nm2-image-upload', '.form-item-nm2-image-path');
    filestyle("#edit-nm1-image-upload", '.form-item-files-nm1-image-upload', '.form-item-nm1-image-path');
    filestyle("#edit-header-video-image-fallback-upload", '.form-item-files-header-video-image-fallback-upload', '.form-item-header-video-image-fallback');
    filestyle("#edit-nf-video-image-fallback-upload", '.form-item-files-nf-video-image-fallback-upload', '.form-item-nf-video-image-fallback');
    filestyle("#edit-header-slide-image-fallback-upload", '.form-item-files-header-slide-image-fallback-upload', '.form-item-header-slide-image-fallback');
    filestyle("#edit-nf-slide-image-fallback-upload", '.form-item-files-nf-slide-image-fallback-upload', '.form-item-nf-slide-image-fallback');
    filestyle("#edit-team-background-upload", '.form-item-files-team-background-upload', '.form-item-team-background-path');
	$(document).bind('keydown', function (e) {
		var
			$open1    = $('#dk_container_edit-choose-bg.dk_open'),
			$focused1 = $('#dk_container_edit-choose-bg.dk_focus'),
			$dk1 = null;

		if ($open1.length) {
			$dk1 = $open1;
		} else if ($focused1.length && !$open1.length) {
			$dk1 = $focused1;
		}
		
		if ((e.keyCode == 13) && $dk1) {
			changebackground($('#dk_container_edit-choose-bg .dk_option_current a').attr('data-dk-dropdown-value'));
		}
		
		var
			$open2    = $('#dk_container_edit-ht-type.dk_open'),
			$focused2 = $('#dk_container_edit-ht-type.dk_focus'),
			$dk2 = null;

		if ($open2.length) {
			$dk2 = $open2;
		} else if ($focused2.length && !$open2.length) {
			$dk2 = $focused2;
		}
		
		if ((e.keyCode == 13) && $dk2) {
			changetopbl($('#dk_container_edit-ht-type .dk_option_current a').attr('data-dk-dropdown-value'));
		}
	});
	
	/* Custom node display */
	shareEnable();
	$('#edit-node-enable').bind('change', function() {
			if ($(this).is(':checked')) {
				$('#md-nodes .md-listleft li').show();
			} else {
				$('#md-nodes .md-listleft li:not(:first)').hide();
			}
	});
	$('#edit-nodetitle-enable').bind('change', function() {
			if ($(this).is(':checked')) {
				$('#node-custom-typo').show();
			} else {
				$('#node-custom-typo').hide();
			}
	});
    $('#edit-typo-view-title-enable').bind('change', function() {
        if ($(this).is(':checked')) {
            $('#typo-view-title-custom-typo').show();
        } else {
            $('#typo-view-title-custom-typo').hide();
        }
    });
    $('#edit-typo-view-description-enable').bind('change', function() {
        if ($(this).is(':checked')) {
            $('#typo-view-description-custom-typo').show();
        } else {
            $('#typo-view-description-custom-typo').hide();
        }
    });
    $('#edit-typo-heading-style-enable').bind('change',function(){
        if ($(this).is(':checked')) {
            $('#typo-heading-style-custom-typo').show();
        } else {
            $('#typo-heading-style-custom-typo').hide();
        }
    });
	$('#edit-typo-heading-style-enable,#edit-node-enable, #edit-nodetitle-enable, #edit-typo-view-title-enable, #edit-typo-view-description-enable,#edit-parallax-1-enabled,#edit-parallax-2-enabled,#edit-parallax-3-enabled,#edit-parallax-4-enabled').trigger('change');



	/* Functions
	--------------------------------------------------------------------------*/
	function toggleBounce() {

		if (marker.getAnimation() != null) {
			marker.setAnimation(null);
		} else {
			marker.setAnimation(google.maps.Animation.BOUNCE);
		}
	}
	function changetopbl(bg) {
		switch (bg) {
			case '1':
				$('.form-item-ht-text').show();
				break;
			default:
				$('.form-item-ht-text').hide();
		}
	}
	
	function filestyle(file, filewrap, path, inputtext) {
		inputtext = typeof inputtext !== 'undefined' ? inputtext : 0;

		$(path).find('.form-text').after($(file));
		$(filewrap).remove();
		
		var self = $(file);
		var text = $('<div class="filetext"><span></span>Upload a file</div>');
								
		self.wrap('<div class="filewrapper btn-upload">').after(text).css({"opacity": "0"}).bind("change", function() {
			if (inputtext == 1) {
				$(path).find('.description').before('<div>File: ' + self.val().replace("C:\\fakepath\\", "") + ' selected</div>');
			} else {
				$(path).find('.form-text').val(self.val().replace("C:\\fakepath\\", ""));
			}
		});
	}
	
	function fakeselect($select, $block, $optionnumber){
		var $block_html = '<div class="'+$block+'wrap clearfix"><ul>';
		var $tmpval = 0;
		for ($i = 0; $i <= $optionnumber; $i++) {
			$tmpval = $($select + " option:eq("+$i+")").val();
			if ($tmpval) {
				$block_html += '<li><div id="'+$block+$tmpval+'" class="slitem"></div></li>';
			}
		}
		$block_html += '</ul></div>';
		
		$($select).parent().append($block_html);
		
		var $tmpselect = $($select + " option[selected]").val();
		$('#' + $block+$tmpselect).parent().addClass('selected');
		
		$('.'+$block+'wrap li').each(function() {
			$(this).click(function(){
				$('.'+$block+'wrap .selected').removeClass('selected');
				$(this).addClass('selected');
				$($select + " option[selected]").removeAttr("selected");
				tmpindex = $(this).find(".slitem").attr('id').replace($block, "")
				$($select + " option[value="+tmpindex+"]").attr("selected", "selected");
			});
		});
		$($select).hide();
	}
	
	function changeimgsize(id, maxw, maxh) {
		$(id + " .imgwidth").after('<div class="slider-width"></div>');
		$(id + " .imgheight").after('<div class="slider-height"></div>');
		$(id + " .constrain").after('<div class="button" style="width: 34px; margin: 5px 0 0">reset</div>');
		resetwidth = imgwidth = $(id + " .slider-img:first").width();
		resetheight = imgheight = $(id + " .slider-img:first").height();
		var ratio = 0;
		$(id + " .constrain").change(function() {
		  if ($(this).is (':checked')) {
				imgwidth = $(id + " .imgwidth").val();
				imgheight = $(id + " .imgheight").val();
			}
		});
		$(id + " .slider-width").slider({
			range: "min",
			value: imgwidth,
			min: 10,
			max: maxw,
			step: 1,
			slide: function( event, ui ) {
				if ($(id + " .constrain:checked").length > 0) {
					ratio = ui.value / imgwidth;
					newheight = jqROund(imgheight * ratio);
					if (newheight > maxh) {
						return false;
					} else {
						$(id + " .slider-height").slider("value", newheight);
						$(id + " .slider-img").height(newheight);
						$(id + " .imgheight").val(newheight);
					}
				}
				$(id + " .imgwidth").val(ui.value);
				$(id + " .slider-img" ).width( ui.value );
			}
		});
		
		$(id + " .slider-height").slider({
			range: "min",
			value: imgheight,
			min: 10,
			max: maxh,
			step: 1,
			slide: function( event, ui ) {
				if ($(id + " .constrain:checked").length > 0) {
					ratio = ui.value / imgheight;
					newwidth = jqROund(imgwidth * ratio);
					if (newwidth > maxw) {
						return false;
					} else {
						$(id + " .slider-width").slider("value", newwidth);
						$(id + " .slider-img").width(newwidth);
						$(id + " .imgwidth").val(newwidth);
					}
				}
				$(id + " .imgheight").val(ui.value);
				$(id + " .slider-img" ).height( ui.value );
			}
		});
		
		$(id + " .button").click(function(){
			imgwidth = resetwidth;
			imgheight = resetheight;
			$(id + " .imgwidth").val(resetwidth);
			$(id + " .slider-width").slider("value", resetwidth);
			$(id + " .imgheight").val(resetheight);
			$(id + " .slider-height").slider("value", resetheight);
			$(id + " .slider-img" ).css({
				'width': resetwidth,
				'height': resetheight
			});
			return false;
		})
	}
	
	function inputtoslide(id, minv, maxv) {
        sliderclass = id.replace("#", "")+'inputtoslide';
		$(id).before('<div class="'+ sliderclass +' inputtoslide"></div>').after(' px');
        $(id).parent().addClass('input-slide');
		$("." + sliderclass).slider({
			value: $(id).val(),
            range: "min",
			min: minv,
			max: maxv,
			step: 1,
			slide: function( event, ui ) {
				$(id).val(ui.value);
			}
		});
        $(id).focusout(function() {
            $(this).prev().slider('value',$(id).val());
        });
    }
	
	function perBackgroundType(item) {
		var custom_checkbox = $('#edit-' + item + '-enable');
		var div = $('#div-' + item + '-collapse');
	
		custom_checkbox.change(
			function() {
				if (custom_checkbox.attr('checked')) {
					div.slideDown();
				}
				else if (div.css('display') != 'none') {
					div.slideUp();
				}
			}
		);
		if (!custom_checkbox.attr('checked')) {
			div.hide();
		}
	}
	
	function shareEnable() {
		var custom_checkbox = $('.node-share-checkbox');
		custom_checkbox.change(
			function() {
				div = $(this).parent().next();
				if ($(this).attr('checked')) {
					div.slideDown();
				}
				else if (div.css('display') != 'none') {
					div.slideUp();
				}
			}
		);
		
		custom_checkbox.each(function() {
			div = $(this).parent().next();
			if (!$(this).attr('checked')) {
				div.hide();
			} else {
				div.show();
			}
		});
	}
	
	function jqROund(a) {
	 return Math.round(a);
	}
	
	$(window).resize(function() {
		listBackgroundw = $(".md-wrap").width() - 300;
		$(".md-listBackground").width(listBackgroundw);
	});
    function iconMarkUp() {
        var iconDefaultMarkUp = Drupal.settings.iconMarkUp;
        var iconMarkUp = '<fieldset id="edit-header-ti-icon-1" class="collapsible form-wrapper collapse-processed"><legend><span class="fieldset-legend"><a href="#" class="fieldset-title"><span class="fieldset-legend-prefix element-invisible">Hide</span> Icon</a><span class="summary"></span></span></legend><div class="fieldset-wrapper"><div class="form-item form-type-select form-item-header-ti-icon-1-icon">'+
            +'<label for="edit-header-ti-icon-1-icon">Select Icon </label>'+
            +'<select name="header_ti_icon_1[icon]" id="edit-header-ti-icon-1-icon" class="form-icon-select form-select">'+iconDefaultMarkUp+'</select>'+
            +'</div>'
        +'</div></fieldset>';
        return iconMarkUp;
    }

});