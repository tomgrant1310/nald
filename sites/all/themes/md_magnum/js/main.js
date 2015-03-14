/*
	01. Smooth scrolling
	02. FitText
	03. Magnific Popup
	04. Sliders
	05. Fading divs
	06. Menu toggle
	07. Fixed menu
	08. Equal portfolio
*/
(function($){

jQuery(document).ready(function($){

// 01. Smooth scrolling - Smooth scroll after clicking an element with the class 'smoothscroll'
    $(function(){
        $('.smoothscroll').bind('click.smoothscroll',function (e){
            //e.preventDefault();
            var target = this.hash,
                $target = $(target);
            if($(target).size() > 0) {
                $('html, body').stop().animate({
                    'scrollTop': $target.offset().top-0
                }, 900, 'swing', function () {
                    window.location.hash = target;
                });
            } else {
                return true;
            }
            e.preventDefault();
        });
    });

// 02. FitText
        $(window).load(function(){
            setTimeout(function(){
                $('h1.fittext').fitText(1, { minFontSize: '50px', maxFontSize: '100px' });
                $('h2.fittext').fitText(1, { minFontSize: '40px', maxFontSize: '80px' });
                $('h3.fittext').fitText(1, { minFontSize: '30px', maxFontSize: '60px' });
                $('h4.fittext').fitText(1, { minFontSize: '20px', maxFontSize: '40px' });
                $('h5.fittext').fitText(1, { minFontSize: '15px', maxFontSize: '30px' });
                $('h6.fittext').fitText(1, { minFontSize: '10px', maxFontSize: '20px' });
            }, 200);
        });

        $('h1.fittext').fitText(1, { minFontSize: '50px', maxFontSize: '100px' });
        $('h2.fittext').fitText(1, { minFontSize: '40px', maxFontSize: '80px' });
        $('h3.fittext').fitText(1, { minFontSize: '30px', maxFontSize: '60px' });
        $('h4.fittext').fitText(1, { minFontSize: '20px', maxFontSize: '40px' });
        $('h5.fittext').fitText(1, { minFontSize: '15px', maxFontSize: '30px' });
        $('h6.fittext').fitText(1, { minFontSize: '10px', maxFontSize: '20px' });
    // Fit Media in blog page

// 03. Magnific Popup - Magnific Popup for images
    $('.popup, .popup-image').magnificPopup({
        type: 'image',
        fixedContentPos: false,
        fixedBgPos: false,
        mainClass: 'mfp-no-margins mfp-with-zoom',
        image: {
            verticalFit: true
        },
        zoom: {
            enabled: true,
            duration: 300
        }
    });
// Magnific Popup for Slider
    $('.popup-gallery').magnificPopup({
        type: 'image',
        gallery: {
            enabled:true
        }
    })
// Magnific Popup for soundcloud
jQuery(document).ready(function(){
    var soundcloudSource = $("#soundcloud-popup").find("iframe").attr("src");
    $(".popup-soundcloud").attr("href",soundcloudSource);
    $("#soundcloud-popup").remove();
})
    $('.popup-soundcloud').magnificPopup({
        type: 'iframe',
        mainClass: 'soundcloud-popup',
        fixedContentPos: false,
        fixedBgPos: false,
        removalDelay: 160,
        preloader: false
    });

// Magnific Popup for videos and google maps
    $('.popup-youtube, .popup-vimeo, .popup-gmaps').magnificPopup({
        disableOn: 700,
        type: 'iframe',
        fixedContentPos: false,
        fixedBgPos: false,
        mainClass: 'mfp-fade',
        removalDelay: 160,
        preloader: false
    });

// Magnific Popup for a normal inline element
    $('.popup-inline').magnificPopup({
        type: 'inline'
    });
// Magnific Popup for a html5 video element
    $('.popup-video').magnificPopup({
        type: 'inline',
        fixedContentPos: false,
        fixedBgPos: false,
        mainClass: 'mfp-no-margins mfp-with-zoom mfp-video'

    });
// Magnific Popup for a project with rich content
        $('.popup-project').magnificPopup({
            type: 'inline',
            alignTop: true
        });

// Magnific Popup for an ajax popup without rich content
        $('.popup-ajax').magnificPopup({
            type: 'ajax',
            fixedContentPos: false,
            fixedBgPos: false,
            mainClass: 'mfp-fade',
            removalDelay: 160,
            preloader: false
        });


// 04. Sliders
   $(document).ready(function(){
       $(window).load(function() {
           // Featured post slider
           $('.flexslider').flexslider({
               animation: "fade",
               nextText: "",
               prevText: "",
               slideshowSpeed: 7000,           //Integer: Set the speed of the slideshow cycling, in milliseconds
               animationSpeed: 600
           });
           // Parallax Slider
           $('.quote-slider').each(function(){
               var delayTime = $(this).attr("data-delay-time") ? $(this).attr("data-delay-time") : 7000;
               $(this).flexslider({
                   animation: "fade",
                   nextText: "",
                   prevText: "",
                   controlNav:false,
                   slideshowSpeed: delayTime,           //Integer: Set the speed of the slideshow cycling, in milliseconds
                   animationSpeed: 600
               });
           })
           // header slider
           $('.header-slider').flexslider({
               animation: "fade",
               nextText: "",
               prevText: "",
               controlNav:false,
               slideshowSpeed: 7000,           //Integer: Set the speed of the slideshow cycling, in milliseconds
               animationSpeed: 600
           });
       });
   });

// 05. Fading divs - Fade a div except the one that's hovered
        if($('html').hasClass('no-touch')){
            $('.portfolio-thumb, .image-thumb, .service-item').hover(function(){
                $(this).siblings().addClass('fade');
            }, function(){
                $(this).siblings().removeClass('fade');
            });
        }

// 06. Menu toggle
    jQuery(document).ready(function(){
        $('#toggle-menu').click(function (e){
            e.stopPropagation();
        });
        $('html').click(function (e){
            if (!$('.toggle-menu').is($(e.target))){
                $('#toggle-menu').prop("checked", false);
            }
        });
    });

// 07. Fixed menu - Fix the menu to the top after you scroll past it
    $(window).load(function(){
        'use strict';
        var menuStickyEnable = Drupal.settings.menuStickyEnable;
        if(menuStickyEnable != null && menuStickyEnable == '1') {
            if($("body").hasClass("toolbar")) {
                $(".fixedmenu").sticky({ topSpacing: 60 });
            } else {
                $(".fixedmenu").sticky({ topSpacing: 0 });
            }

        }
    });
})
/* 08. Use the .equal class on a row if you want the columns to be equal in height */
    $('.equal').children('.columns').equalizeHeight();

    $( window ).resize( function() {
        $( '.equal' ).children( '.columns' ).equalizeHeight();

        setTimeout( function() {

            $( '.equal' ).children( '.columns' ).equalizeHeight();

        }, 100 );

        setTimeout( function() {

            $( '.equal' ).children( '.columns' ).equalizeHeight();

        }, 400 );

        setTimeout( function() {

            $( '.equal' ).children( '.columns' ).equalizeHeight();

        }, 1400 );

        setTimeout( function() {

            $( '.equal' ).children( '.columns' ).equalizeHeight();

        }, 2400 );

    });

    setTimeout( function() {

        $( window ).trigger( 'resize scroll' );

    }, 1000 );

    setTimeout( function() {

        $( window ).trigger( 'resize scroll' );

    }, 3000 );

    $( window ).load( function() {
        $( '.equal' ).children( '.columns' ).equalizeHeight();

        $( window ).trigger( 'resize scroll' );

        setTimeout( function() {

            $( '.equal' ).children( '.columns' ).equalizeHeight();

        }, 1000 );

        setTimeout( function() {

            $( '.equal' ).children( '.columns' ).equalizeHeight();

        }, 1300 );
    })

// 09. Hide filter wrapper in comment box
    jQuery(document).ready(function($){
        $(".filter-wrapper").hide();
    });
//10. Background Slider
    jQuery(document).ready(function($) {
        if($("#pr1-slider").size() > 0 && ($("#pr1-slider .bs-slides li").length) > 1) {
            var effect = Drupal.settings.pr1SlideEffect
            slideDelay = Drupal.settings.pr1SlideDelay
            effectTime = Drupal.settings.pr1EffectTime;
            $('#pr1-slider').backslider({
                mode: 'timer',
                effect: 'crossfade',
                timerDelay: 4000,
                effectEasing: 'swing',
                effectTime: 800,
                centerImages: true
            });
        }
        if($("#pr2-slider").size() > 0 && ($("#pr2-slider .bs-slides li").length) > 1) {
            var effect = Drupal.settings.pr2SlideEffect
            slideDelay = Drupal.settings.pr2SlideDelay
            effectTime = Drupal.settings.pr2EffectTime;
            $('#pr2-slider').backslider({
                mode: 'timer',
                effect: 'crossfade',
                timerDelay: 4000,
                effectEasing: 'swing',
                effectTime: 800,
                centerImages: true
            });
        }
        if($("#pr3-slider").size() > 0 && ($("#pr3-slider .bs-slides li").length) > 1) {
            var effect = Drupal.settings.pr3SlideEffect
            slideDelay = Drupal.settings.pr3SlideDelay
            effectTime = Drupal.settings.pr3EffectTime;
            $('#pr3-slider').backslider({

                mode: 'timer',
                effect: 'crossfade',
                timerDelay: 4000,
                effectEasing: 'swing',
                effectTime: 800,
                centerImages: true
            });
        }
        if($("#footer-slider").size() > 0 && ($("#footer-slider .bs-slides li").length) > 1) {
            var effect = Drupal.settings.ftSlideEffect
            slideDelay = Drupal.settings.ftSlideDelay
            effectTime = Drupal.settings.ftEffectTime;
            $('#footer-slider').backslider({
                mode: 'timer',
                effect: 'crossfade',
                timerDelay: 4000,
                effectEasing: 'swing',
                effectTime: 800,
                centerImages: true
            });
        }
        if($("#nf-slider").size() > 0 && ($("#nf-slider .bs-slides li").length) > 1){
            var effect = Drupal.settings.nfSlideEffect
            slideDelay = Drupal.settings.nfSlideDelay
            effectTime = Drupal.settings.nfEffectTime;
            $('#nf-slider').backslider({
                mode: 'timer',
                effect: 'crossfade',
                timerDelay: 4000,
                effectEasing: 'swing',
                effectTime: 800,
                centerImages: true
            });
        }
        if($("#header-slider").size() > 0 && ($("#header-slider .bs-slides li").length) > 1){
            var effect = Drupal.settings.hdSlideEffect
                slideDelay = Drupal.settings.hdSlideDelay
                effectTime = Drupal.settings.hdEffectTime;
            $('#header-slider').backslider({
                mode: 'timer',
                timerDelay: slideDelay,
                effect: 'crossfade',
                effectEasing: ''+effect+'',
                effectTime: effectTime,
                centerImages: true
            });
        }
    })
// 11. Parallax video background
    jQuery(document).ready(function($){
        var onMobile = false;
        if( /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent) ) { onMobile = true; }
        if( ( onMobile === false ) ) {
            // The Parallax background video
            if($(".pr1-video").size() > 0) {
                var pr1VideoRes = Drupal.settings.pr1VideoRes;
                $(".pr1-video").mb_YTPlayer({
                    containment: "#pr1-video-bg",
                    opacity: 1, // Set the opacity of the player;
                    mute: true, // Mute the audio;
                    // ratio: "4/3" or "16/9" to set the aspect ratio of the movie;
                    quality:pr1VideoRes,// quality: "default" or "small", "medium", "large", "hd720", "hd1080", "highres";
                    // containment: The CSS selector of the DOM element where you want the video background; if not specified it takes the "body"; if set to "self" the player will be instanced on that element;
                    // optimizeDisplay: True will fit the video size into the window size optimizing the view;
                    loop: true, // True or false loops the movie once ended.
                    // vol: 1 to 100 (number) set the volume level of the video.
                    startAt: 0, // Set the seconds the video should start at.
                    autoPlay: true, // True or false play the video once ready.
                    showYTLogo: false, // Show or hide the YT logo and the link to the original video URL.
                    showControls: false, // Show or hide the controls bar at the bottom of the page.
                    addRaster: true // Show or hide the background raster image
                });
                // First we're going to hide these elements
                $("#pr1-video-controls .small-play-btn").hide();

                // Start the movie
                $("#pr1-video").on("YTPStart",function(){
                    $("#pr1-video-controls .small-play-btn").hide();
                    $("#pr1-video-controls .small-pause-btn").show();
                });

                // Pause the movie
                $("#pr1-video").on("YTPPause",function(){
                    $("#pr1-video-controls .small-play-btn").show();
                    $("#pr1-video-controls .small-pause-btn").hide();
                });
            }
            if($(".pr2-video").size() > 0) {
                var pr2VideoRes = Drupal.settings.pr2VideoRes;
                $(".pr2-video").mb_YTPlayer({
                    containment: "#pr2-video-bg",
                    opacity: 1, // Set the opacity of the player;
                    mute: true, // Mute the audio;
                    // ratio: "4/3" or "16/9" to set the aspect ratio of the movie;
                    quality:pr2VideoRes,// quality: "default" or "small", "medium", "large", "hd720", "hd1080", "highres";
                    // containment: The CSS selector of the DOM element where you want the video background; if not specified it takes the "body"; if set to "self" the player will be instanced on that element;
                    // optimizeDisplay: True will fit the video size into the window size optimizing the view;
                    loop: true, // True or false loops the movie once ended.
                    // vol: 1 to 100 (number) set the volume level of the video.
                    startAt: 0, // Set the seconds the video should start at.
                    autoPlay: true, // True or false play the video once ready.
                    showYTLogo: false, // Show or hide the YT logo and the link to the original video URL.
                    showControls: false, // Show or hide the controls bar at the bottom of the page.
                    addRaster: true // Show or hide the background raster image
                });
                // First we're going to hide these elements
                $("#pr2-video-controls .small-play-btn").hide();

                // Start the movie
                $("#pr2-video").on("YTPStart",function(){
                    $("#pr2-video-controls .small-play-btn").hide();
                    $("#pr2-video-controls .small-pause-btn").show();
                });

                // Pause the movie
                $("#pr2-video").on("YTPPause",function(){
                    $("#pr2-video-controls .small-play-btn").show();
                    $("#pr2-video-controls .small-pause-btn").hide();
                });
            }
            if($(".pr3-video").size() > 0) {
                var pr3VideoRes = Drupal.settings.pr3VideoRes;
                $(".pr3-video").mb_YTPlayer({
                    containment: "#pr3-video-bg",
                    opacity: 1, // Set the opacity of the player;
                    mute: true, // Mute the audio;
                    // ratio: "4/3" or "16/9" to set the aspect ratio of the movie;
                    quality:pr3VideoRes,// quality: "default" or "small", "medium", "large", "hd720", "hd1080", "highres";
                    // containment: The CSS selector of the DOM element where you want the video background; if not specified it takes the "body"; if set to "self" the player will be instanced on that element;
                    // optimizeDisplay: True will fit the video size into the window size optimizing the view;
                    loop: true, // True or false loops the movie once ended.
                    // vol: 1 to 100 (number) set the volume level of the video.
                    startAt: 0, // Set the seconds the video should start at.
                    autoPlay: true, // True or false play the video once ready.
                    showYTLogo: false, // Show or hide the YT logo and the link to the original video URL.
                    showControls: false, // Show or hide the controls bar at the bottom of the page.
                    addRaster: true // Show or hide the background raster image
                });
                // First we're going to hide these elements
                $("#pr3-video-controls .small-play-btn").hide();

                // Start the movie
                $("#pr3-video").on("YTPStart",function(){
                    $("#pr3-video-controls .small-play-btn").hide();
                    $("#pr3-video-controls .small-pause-btn").show();
                });

                // Pause the movie
                $("#pr3-video").on("YTPPause",function(){
                    $("#pr3-video-controls .small-play-btn").show();
                    $("#pr3-video-controls .small-pause-btn").hide();
                });
            }

        }

    });
    // 12. Header video background
    jQuery(document).ready(function($){
        if($("#header-video").size() > 0) {
            var onMobile = false;
            var headerVdAutoPlay = Drupal.settings.headerVideoAutoPlay;
            var headerVideoRes = Drupal.settings.headerVideoRes;
            if( /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent) ) { onMobile = true; }
            if( ( onMobile === false ) ) {
                // The videoplayer - controlled background video
                $(".fullscreen-video").mb_YTPlayer({
                    containment: "body",
                    opacity: 1, // Set the opacity of the player;
                    mute: true, // Mute the audio;
                    // ratio: "4/3" or "16/9" to set the aspect ratio of the movie;
                    quality: headerVideoRes,// quality: "default" or "small", "medium", "large", "hd720", "hd1080", "highres";
                    // containment: The CSS selector of the DOM element where you want the video background; if not specified it takes the "body"; if set to "self" the player will be instanced on that element;
                    // optimizeDisplay: True will fit the video size into the window size optimizing the view;
                    loop: false, // True or false loops the movie once ended.
                    // vol: 1 to 100 (number) set the volume level of the video.
                    startAt: 0, // Set the seconds the video should start at.
                    autoPlay: headerVdAutoPlay, // True or false play the video once ready.
                    showYTLogo: false, // Show or hide the YT logo and the link to the original video URL.
                    showControls: false // Show or hide the controls bar at the bottom of the page.
                });

                // Start the movie
                if(headerVdAutoPlay == true) {
                    // First we're going to hide these elements
                    $("#header-video-controls .small-play-btn").hide();

                    // Start the movie
                    $("#header-video").on("YTPStart",function(){
                        $("#header-video-controls.video-controls .small-play-btn").hide();
                        $("#header-video-controls.video-controls .small-pause-btn").show();
                    });

                    // Pause the movie
                    $("#header-video").on("YTPPause",function(){
                        $("#header-video-controls .small-play-btn").show();
                        $("#header-video-controls .small-pause-btn").hide();
                    });
                }
                if (headerVdAutoPlay == false){
                    // First we're going to hide these elements
                    $("#header-video-controls.video-controls").hide();
                    $("#header-video").on("YTPStart",function(){
                        $("#header-video-controls.video-controls").show().css({opacity: 0, visibility: "visible"}).animate({opacity: 1},300);
                        $(".fullscreen-img, .home-content").css({opacity: 1, visibility: "hidden"}).animate({opacity: 0},300);
                    });

                    // Pause the movie
                    $("#header-video").on("YTPPause",function(){
                        $(".fullscreen-img, .home-content").css({opacity: 0, visibility: "visible"}).animate({opacity: 1},300);
                        $("#header-video-controls.video-controls").css({opacity: 1, visibility: "hidden"}).animate({opacity: 0},300);
                    });

                    // After the movie
                    $("#header-video").on("YTPEnd",function(){
                        $("#header-video-controls.video-controls").hide();
                        $(".fullscreen-img, .home-content").css({opacity: 0, visibility: "visible"}).animate({opacity: 1},300);
                    });
                }

            } else {
                // Fallback for mobile devices
                $("#home").removeClass(".video");
                $(".fullscreen-video,#header-video-controls.video-controls, .play-btn-normal").hide();
            }
        }
// 13. Footer video background
        if($(".footer-video").size() > 0) {
            var ftVideoRes = Drupal.settings.ftVideoRes;
            $(".footer-video").mb_YTPlayer({
                containment: "#footer-video-bg",
                opacity: 1, // Set the opacity of the player;
                mute: true, // Mute the audio;
                // ratio: "4/3" or "16/9" to set the aspect ratio of the movie;
                quality:ftVideoRes,// quality: "default" or "small", "medium", "large", "hd720", "hd1080", "highres";
                // containment: The CSS selector of the DOM element where you want the video background; if not specified it takes the "body"; if set to "self" the player will be instanced on that element;
                // optimizeDisplay: True will fit the video size into the window size optimizing the view;
                loop: true, // True or false loops the movie once ended.
                // vol: 1 to 100 (number) set the volume level of the video.
                startAt: 0, // Set the seconds the video should start at.
                autoPlay: true, // True or false play the video once ready.
                showYTLogo: false, // Show or hide the YT logo and the link to the original video URL.
                showControls: false, // Show or hide the controls bar at the bottom of the page.
                addRaster: true // Show or hide the background raster image
            });
            // First we're going to hide these elements
            $("#footer-video-controls .small-pause-btn").hide();

            // Start the movie
            $("#footer-video").on("YTPStart",function(){
                $("#footer-video-controls .small-play-btn").hide();
                $("#footer-video-controls .small-pause-btn").show();
            });

            // Pause the movie
            $("#footer-video").on("YTPPause",function(){
                $("#footer-video-controls .small-play-btn").show();
                $("#footer-video-controls .small-pause-btn").hide();
            });
        }
// 14. 404 page video background
        if($("#nf-video").size() > 0) {
            var onMobile = false;
            if( /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent) ) { onMobile = true; }
            if( ( onMobile === false ) ) {
                var nfVideoRes = Drupal.settings.nfVideoRes;
                // The videoplayer - controlled background video
                $("#nf-video").mb_YTPlayer({
                    containment: "body",
                    opacity: 1, // Set the opacity of the player;
                    mute: true, // Mute the audio;
                    // ratio: "4/3" or "16/9" to set the aspect ratio of the movie;
                    quality:nfVideoRes,// quality: "default" or "small", "medium", "large", "hd720", "hd1080", "highres";
                    // containment: The CSS selector of the DOM element where you want the video background; if not specified it takes the "body"; if set to "self" the player will be instanced on that element;
                    // optimizeDisplay: True will fit the video size into the window size optimizing the view;
                    loop: false, // True or false loops the movie once ended.
                    // vol: 1 to 100 (number) set the volume level of the video.
                    startAt: 0, // Set the seconds the video should start at.
                    autoPlay: true, // True or false play the video once ready.
                    showYTLogo: false, // Show or hide the YT logo and the link to the original video URL.
                    showControls: false // Show or hide the controls bar at the bottom of the page.
                });
                // First we're going to hide these elements
                $("#nf-video-controls.video-controls .small-play-btn").hide();
                // Start the movie
                $("#nf-video").on("YTPStart",function(){
                    $("#nf-video-controls.video-controls .small-play-btn").hide();
                    $("#nf-video-controls.video-controls .small-pause-btn").show();
                });
                // Pause the movie
                $("#nf-video").on("YTPPause",function(){
                    $("#nf-video-controls.video-controls .small-play-btn").show();
                    $("#nf-video-controls.video-controls .small-pause-btn").hide();
                });
                // After the movie
                $("#nf-video").on("YTPEnd",function(){
                    $("#nf-video-controls.video-controls").hide();
                    $(".video-fullscreen-img").css({opacity: 0, visibility: "visible"}).animate({opacity: 1},300);
                });
            } else {
                // Fallback for mobile devices
                $(".fullscreen-video,#nf-video-controls.video-controls, .play-btn-normal").hide();
            }
        }
    });
//15. Hide Backtop button
    if($("body").hasClass("front")) {
        $(".back-top").show();
    } else {
        $(".back-top").hide();
    }
})(jQuery);


