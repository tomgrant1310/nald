/**
 * Backslider - Fullscreen Background Image Slider 
 * http://plugins.gravitysign.com/backslider
 * Copyright (c) 2013 Roman Yurchuk
 * Version 1.8.1
*/


(function($){
	
	// method to replace calling object for a function
	Function.prototype.scope = function(c){
		var f = this; 
		return function(){
			f.apply(c, Array.prototype.slice.call(arguments));
		};
	};


	/* BackSlider Constructor
	*************************************************************************/
	
	function BackSlider(c,s){
		this.container = $(c);
		this.settings = s;
		
		//create container
		if(this.container.find('.bs-slides').length == 0){
			this.container.append('<ul class="bs-slides"></ul>')
		}
		
		//load slides from given source
		if(this.settings.photoSource == 'flickrfeed') {
			this.photoSourceFlickrFeed();
		} else if(this.settings.photoSource == 'flickrauth') {
			this.photoSourceFlickrAuth();
		} else if(this.settings.photoSource == 'picasa') {
			this.photoSourcePicasa();
		} else {
			this.init();
		}
	}
	
	
	/* Backslider Init
	*************************************************************************/
	
	BackSlider.prototype.init = function(){
	
		// set variables
		this.slides = this.container.find('.bs-slides > li');
		this.length = this.slides.length;
		
		//start with random slide
		if(this.settings.startRandom){
			this.index = Math.floor(Math.random()*(this.length-1));
		} else {
			this.index = this.settings.startSlide || 0;
		}
		
		//add overlay div
		this.container.prepend('<div class="bs-overlay"></div>');
		
		//add controls div
		this.container.prepend('<div class="bs-controls"></div>');
		
		//add preload div
		if(this.settings.preload){
			this.container.prepend('<div class="bs-preload"><div class="bs-preload-indicator"></div></div>');
		}
		
		// wait for images to load
		this.preloadTimer = window.setInterval((function(){
		
			// get all images that have not been loaded yet
			var n = this.slides.find('img').filter(function(){
				return !this.complete;
			}).length;
			
			if(n == 0){
				//stop preload timer if all images have loaded
				window.clearInterval(this.preloadTimer);
				
				//check if preload is enabled
				if(this.settings.preload){
					var preload = this.container.find('.bs-preload');
					preload.delay(this.settings.preloadDelay).fadeTo(this.settings.preloadTime, 0, (function(){
						this.container.find('.bs-controls').fadeIn('fast');
						preload.remove();
					}).scope(this));
				} else {
					this.container.find('.bs-controls').fadeIn('fast');
				}
				
				// save image size in "data-width" and "data-height" attributes;
				// we use them centerImages() method to overcome problem with display:none on parent
				this.slides.find('img').each(function(){
					$(this).attr('data-width', this.width).attr('data-height', this.height);
				});
				
				//set initial image orientation and center images
				this.imageScaleMode();
				this.centerImages();
				
				//run slidesLoaded callback
				this.settings.slidesLoaded.scope(this.container.get(0))(this.length);
			}
			
		}).scope(this),200);
			
		//make first slide active
		this.slides.not(':eq('+this.index+')').hide();
								
		//for "slidefade" effect increase size of list items in .bs-slides UL 
		if(this.settings.effect == 'slidefade'){
			var w = 100 + Math.abs(this.settings.slidefadeOffsetX)*100/this.container.width();
			var h = 100 + Math.abs(this.settings.slidefadeOffsetY)*100/this.container.height();
		 	this.slides.css({width: w.toFixed(3)+'%', height: h.toFixed(3)+'%'});
	 	}
	 	
	 	//add window resize handler to scale images and change orientation
		$(window).resize((function(){
			this.imageScaleMode();
			this.centerImages();
		}).scope(this));
	 	
	 	//register custom "backslider" event type
		this.container.bind('backslider',(function(e,a,p){
			if(typeof this[a] == 'function'){
				this[a].scope(this)(p);
			}
			e.stopPropagation();
		}).scope(this));
		
		//check if mode and effect were properly set
		this.settings.mode = this.modes.hasOwnProperty(this.settings.mode) ? this.settings.mode : 'timer';
		this.settings.effect = this.effects.hasOwnProperty(this.settings.effect) ? this.settings.effect : 'fade';
		
		// activate mode for backslider (every mode will do final setup of backslider environment)
		this.modes[this.settings.mode].scope(this)();
	};
		
	
	/* BackSlider Modes
	*************************************************************************/
	
	BackSlider.prototype.modes = {
		timer: function(){
			$('<a class="bs-timer" href="#bs"></a>').click((function(e){
				(this.timer)?this.pause():this.resume();
				e.preventDefault();
			}).scope(this)).appendTo(this.container.find('.bs-controls'));
			this.resume();
		},
		scroll: function(){
			var point = 0, step = 0;
			$('<div class="bs-scroll"></div>').appendTo(this.container.find('.bs-controls'));
			$(window).bind('resize',(function(){
				step = ($(document).height()-$(window).height())/(this.length-1);
			}).scope(this)).trigger('resize');
			if(step > 0){
				$(window).bind('scroll',(function(){
					point = Math.floor($(window).scrollTop()/step);
					if(this.index != point){
						window.clearTimeout(this.timer);
						this.timer = window.setTimeout((function(){
							this.slides.stop(true,true);
							if(this.index != point){
								this.skip(point);
							}
						}).scope(this),this.settings.scrollTimeout);
					}
					
				}).scope(this));
			}
		},
		controls: function(){
			$('<a class="bs-previous" href="#bs"></a>').click((function(e){
				this.previous();
				e.preventDefault();
			}).scope(this)).appendTo(this.container.find('.bs-controls'));
			$('<a class="bs-next" href="#bs"></a>').click((function(e){
				this.next();
				e.preventDefault();
			}).scope(this)).appendTo(this.container.find('.bs-controls'));
			
		},
		pagination: function(){
			for(var i = 0; i < this.length; i++){
				(function(p){
					$('<a class="bs-pagination" href="#bs'+p+'"></a>').click((function(e){
						this.skip(p);
						e.preventDefault();
					}).scope(this)).appendTo(this.container.find('.bs-controls'));
				}).scope(this)(i);
			}
			this.skip(this.index);
			this.updateControls();
		},
		thumbnails: function(){
			var time = this.settings.thumbnailsTime;
			var opacity = this.settings.thumbnailsOpacity;
			var size = parseInt(this.settings.thumbnailsSize, 10) + 'px';
			for(var i = 0; i < this.length; i++){
				(function(p){
					var img = this.slides.eq(p).find('img');
				 	var thumb = new Image();
				 	thumb.alt = img.attr('alt');
					$(thumb).bind('load',function(){
						$(this).css((thumb.width/thumb.height>1) ? 'height' : 'width', size);
						$(this).removeAttr('width').removeAttr('height'); //for IE
					}).hover(function(){
						$(this).stop().fadeTo(time,1);
					},function(){
						if(!$(this).parent().hasClass('bs-active')){
							$(this).stop().fadeTo(time,opacity);
						}
					}).css('opacity',opacity);
					thumb.src = img.attr('src');
					$('<a class="bs-thumbnails" href="#bs'+p+'"></a>').
					css({width: size, height: size}).click((function(e){
						this.skip(p);
						e.preventDefault();
					}).scope(this)).append(thumb).appendTo(this.container.find('.bs-controls'));
				}).scope(this)(i);
			}
			this.skip(this.index);
			this.updateControls();
		}
	};


	/* BackSlider Effects (c - current slide, n - new slide)
	*************************************************************************/
	
	BackSlider.prototype.effects = {
		fade: function(c,n){
			this.settings.beforeSlide.scope(this.container.get(0))(this.index,this.length);
			c.stop().fadeOut(this.settings.effectTime/2,this.settings.effectEasing,(function(){
					n.stop().fadeIn(this.settings.effectTime/2,this.settings.effectEasing,(function(){
						this.settings.afterSlide.scope(this.container.get(0))(this.index,this.length);
					}).scope(this));
				}
			).scope(this));
		},
		crossfade: function(c,n){
			this.settings.beforeSlide.scope(this.container.get(0))(this.index,this.length);
			c.stop().fadeOut(this.settings.effectTime,this.settings.effectEasing);
			n.stop().fadeIn(this.settings.effectTime,this.settings.effectEasing,(function(){
				this.settings.afterSlide.scope(this.container.get(0))(this.index,this.length);
			}).scope(this));
		},
		slidefade: function(c,n){
			var s = {left:this.settings.slidefadeOffsetX,top:this.settings.slidefadeOffsetY,x:0,y:0};
			if(this.settings.slidefadeOffsetX > 0){
		 		s.x = -this.settings.slidefadeOffsetX;
		 		s.left = 0;
		 	} 
		 	if(this.settings.slidefadeOffsetY > 0){
		 		s.y = -this.settings.slidefadeOffsetY;
		 		s.top = 0;
		 	}	
			this.settings.beforeSlide.scope(this.container.get(0))(this.index,this.length);		
		 	c.css('z-index','').stop().fadeOut(this.settings.effectTime,this.settings.effectEasing);
			n.css($.extend({display:'block',opacity:0,'z-index':20},s)).
			stop().animate({opacity:1,top:s.y,left:s.x},
			this.settings.effectTime,this.settings.effectEasing,(function(){
				this.settings.afterSlide.scope(this.container.get(0))(this.index,this.length);
			}).scope(this));
		},
		slide: function(c,n){
			var coverslide = this.container.children('.bs-coverslide');
			if(!coverslide.length){
				coverslide = $('<div class="bs-coverslide"><img src="" alt="Cover Slide"></div>');
				coverslide.prependTo(this.container);
			}
			this.settings.beforeSlide.scope(this.container.get(0))(this.index,this.length);
			coverslide.find('img').attr('src', c.find('img').attr('src')).css({
				position: 'relative',
				top: c.find('img').position().top,
				left: c.find('img').position().left,
				width: c.find('img').width(),
				height: c.find('img').height()
			});
			coverslide.css('width','100%').stop(true).animate({width:'0%'},
			this.settings.effectTime,this.settings.effectEasing,
			(function(){
				this.settings.afterSlide.scope(this.container.get(0))(this.index,this.length);
			}).scope(this));	
			n.css('left',this.settings.slideOffset).show().stop(true,true).
			animate({left:'0px'},this.settings.effectTime,this.settings.effectEasing);
			c.hide();
		}
	};
	
	
	/* BackSlider API Methods
	*************************************************************************/
	
	BackSlider.prototype.next = function() {
		this.slides.stop(true,true);
		this.effects[this.settings.effect].scope(this)(this.currentSlide(),this.nextSlide());
		this.updateControls();
		this.reset();
	};
	
	BackSlider.prototype.previous = function() {
		var p = this.index;
		this.slides.stop(true,true);
		this.effects[this.settings.effect].scope(this)(this.currentSlide(),this.previousSlide());
		this.updateControls();
		this.reset();
	};
	
	BackSlider.prototype.skip = function(n) {
		if(this.index != n){
			var p = this.index;
			this.slides.stop(true,true);
			this.effects[this.settings.effect].scope(this)(this.currentSlide(),this.positionSlide(n));
			this.updateControls();
			this.reset();
		}
	};
	
	BackSlider.prototype.pause = function(){
		if(this.settings.mode == 'timer'){
			this.container.find('.bs-timer').stop().fadeTo('fast',0,function(){
				$(this).css('background-position','0px -80px').fadeTo('fast',1);
			});
			window.clearInterval(this.timer);
			this.timer = 0;	
		}
	};
	
	BackSlider.prototype.resume = function(){
		if(this.settings.mode == 'timer'){
			var t = this.container.find('.bs-timer');
			t.stop().fadeTo('fast',0,function(){
				$(this).css('background-position','-20px 0px').fadeTo('fast',1);
			});
			var n = 0;
			this.timer = window.setInterval((function(){
				t.css('background-position','0px '+(-20*n)+'px');
				n = n + 1; 
				if(n == 4) {
					this.next(); n = 0;
				}
			}).scope(this),this.settings.timerDelay/4);
		}
	};
	
	BackSlider.prototype.reset = function(){
		this.pause();
		this.resume();
	};
	
	
	/* BackSlider Internals
	*************************************************************************/
	
	//get current slide
	BackSlider.prototype.currentSlide = function(){
		return this.slides.eq(this.index);
	};
			
	//get next slide
	BackSlider.prototype.nextSlide = function(){
		
		this.index = (this.index < this.length-1)?this.index+1:0;
		return this.currentSlide();
	};
	
	//get previous slide
	BackSlider.prototype.previousSlide = function(){
		this.index = (this.index > 0)?this.index-1:this.length-1;
		return this.currentSlide();
	};	
	
	//get slide at specific position
	BackSlider.prototype.positionSlide = function(n){
		this.index = parseInt(n, 10);
		return this.currentSlide();
	};
	
	//update controls accordingly with current slide position
	BackSlider.prototype.updateControls = function(){
		// pagination mode
		if(this.settings.mode == 'pagination'){
			this.container.find('.bs-pagination').removeClass('bs-active').eq(this.index).addClass('bs-active');
		}	
		
		// thumbnails mode
		if(this.settings.mode == 'thumbnails'){ 
			this.container.find('.bs-active').removeClass('bs-active').children('img').
			stop().fadeTo(this.settings.thumbnailsTime,this.settings.thumbnailsOpacity);
			this.container.find('.bs-thumbnails:eq('+this.index+')').addClass('bs-active').
			children('img').css('opacity',1);
		}
	};
	
	//set proper image orientation when window is being resized
	BackSlider.prototype.imageScaleMode = function(){
		var container_ratio = this.container.width()/this.container.height();
		this.slides.find('img').each(function(){
			if(this.height > 0) {
				var image_ratio = this.width/this.height;
				this.className = (container_ratio > image_ratio) ? 'bs-landscape' : 'bs-portrait';
			} else {
				this.className = 'bs-landscape';
			}
		});
	};
	
	//keep images centered when window is being resized
	BackSlider.prototype.centerImages = function(){
		if(this.settings.centerImages) {
			var container = this.container;
		    this.slides.find('img').each(function(){
		            var img = $(this), offset = 0;
		            var ratio = img.data('width')/img.data('height');
		            if(img.hasClass('bs-landscape')) {
		                    offset = -(container.width()/ratio - container.height()) / 2;
		                    if(offset > 0) offset = 0;
		                    img.css({position:'relative', top:offset, left:0});
		            } else {
		                    offset = -(container.height() * ratio - container.width()) / 2;
		                    if(offset > 0) offset = 0;
		                    img.css({position:'relative', top:0, left:offset});
		            }
		    });
	    }
	};
	
	
	/* Methods to import images from Flickr and Picasa
	*************************************************************************/
	
	//converts range to plain number sequence, e.g. 1-4,5 to 1,2,3,4,5
	BackSlider.prototype.getPhotoRange = function(mixed){
		var regexp = /(\d+)-(\d+)/g, match;
		while (match = regexp.exec(mixed)) {
		    var seq = '';
		    for (var n = parseInt(match[1],10); n <= parseInt(match[2],10); n++) {
		        seq += n + ',';
		    }
		    mixed = mixed.replace(match[0],seq.substr(0,seq.length-1));
		}
		return mixed;
	};
	
	//imports images using Flickr Feed API
	BackSlider.prototype.photoSourceFlickrFeed = function(){
		var base = 'http://api.flickr.com/services/feeds/photoset.gne';
		var query = '';
		for(var key in this.settings.flickrFeedQuery){
			query += key+'='+this.settings.flickrFeedQuery[key]+'&';
		}
		query += 'lang=en-us&format=json&jsoncallback=?';

		//send api request using photoset.gne feed
		$.getJSON(base,query,(function(json){
			var list = '';
			var range = this.getPhotoRange(this.settings.photoRange);
			$.each(json.items,function(i,item){
				if(range === '' || range.search(new RegExp('\\b'+i+'\\b')) != -1){
					list += '<li>'+'<img src="'+item.media.m.replace('_m','_b')+
					'" alt="'+item.title.replace('"','\'')+'">'+'</li>';
					list += "\r\n";
				}
			});
			this.container.find('.bs-slides').html(list);
			this.init(); //Backslider.init()
		}).scope(this));
	};
	
	//imports images using Flickr API with AuthKey
	BackSlider.prototype.photoSourceFlickrAuth = function(){
		var base = 'http://api.flickr.com/services/rest/';
		var query = '';
		for(var key in this.settings.flickrAuthQuery){
			query += key+'='+this.settings.flickrAuthQuery[key]+'&';
		}
		query += 'method=flickr.photosets.getPhotos&extras=url_o&format=json&jsoncallback=?';
		
		//send api request using flickr.photosets.getPhotos method
		$.getJSON(base,query,(function(json){
			var list = '';
			var range = this.getPhotoRange(this.settings.photoRange);
			$.each(json.photoset.photo,function(i,item){
				if(range === '' || range.search(new RegExp('\\b'+i+'\\b')) != -1){
					list += '<li>'+'<img src="'+item.url_o+'" alt="'+item.title.replace('"','\'')+'">'+'</li>';
					list += "\r\n";
				}
			});
			this.container.find('.bs-slides').html(list);
			this.init(); //Backslider.init()
		}).scope(this));
	};
	
	//imports images using Picasa API
	BackSlider.prototype.photoSourcePicasa = function(){
		var base = 'https://picasaweb.google.com/data/feed/base/user/'+
		this.settings.picasaQuery.user+'/albumid/'+this.settings.picasaQuery.album;
		var query='alt=json&kind=photo&hl=en_US&fields=entry(title,media:group(media:content))';
		
		//send api request
		$.getJSON(base,query,(function(json){
			var list = '';
			var range = this.getPhotoRange(this.settings.photoRange);
			$.each(json.feed.entry,function(i,item){
				if(range === '' || range.search(new RegExp('\\b'+i+'\\b')) != -1){
					var t = item.title.$t.replace('"','\'');
					var s = item.media$group.media$content[0].url;
					list += '<li>'+'<img src="'+s+'" alt="'+t+'">'+'</li>';
					list += "\r\n";
				}
			});
			this.container.find('.bs-slides').html(list);
			this.init(); //Backslider.init()
		}).scope(this));
	};
	
	
	/* jQuery Plugin 
	*************************************************************************/
	
	$.fn.backslider = function(s){
		//default settings
		var settings = $.extend(true,{
			mode: 'controls',				// mode - "controls", "timer", "scroll", "pagination", "thumbnails"
			effect: 'fade',					// effect - "fade", "crossfade", "slidefade", "slide"
			effectTime:	1500,				// effect animation time
			effectEasing: 'swing',			// effect animation easing
			slideOffset: 50,				// "slide" effect offset
			slidefadeOffsetX: 0,			// "slidefade" effect X offset
			slidefadeOffsetY: -50,			// "slidefade" effect Y offset
			timerDelay: 5000,				// slideshow timer delay (for "timer" mode)
			scrollTimeout: 200,				// timeout before switching slides (for "scroll" mode)
			preload: true, 					// preload images
			preloadTime: 1000,				// preload animation time 
			preloadDelay: 200,				// preload animation delay  
			startSlide: 0,					// slide to begin with
			startRandom: false,				// start on random slide
			thumbnailsSize: '40px',			// thumbnails size (for "thumbnails" mode)
			thumbnailsOpacity: 0.5,			// thumbnails opacity (for "thumbnails" mode)
			thumbnailsTime: 500,			// thumbnails animation time (for "thumbnails" mode)
			centerImages: false,			// always center slide images
			photoSource: 'none',			// photo source - "flickrfeed", "flickrauth", "picasa" or "none"
			photoRange: '',					// photo range ("" or "1-3,5,6,7-9")
			flickrFeedQuery: {				// query arguments for "flickrfeed" photoSource
				set: '00000000',			// set ID
				nsid: '00000000@N00'		// user ID
			},
			flickrAuthQuery: {				// query arguments for "flickrauth" photoSource
				api_key: '00000000',		// auth key
				photoset_id: '00000000'		// set ID
			},
			picasaQuery: {					// query arguments for "picasa" photoSource
				user: 'username',			// picasa user name
				album: '00000000'			// picasa album ID
			},
			beforeSlide: function(){},		// before slide callback
			afterSlide: function(){},		// after slide callback
			slidesLoaded: function(){}		// slide images loaded callback
		},s);
		
		if(this.length) {
			//create BackSlider
			this.data('backslider', new BackSlider(this,settings));
		}
		
		return this;
	};
})(jQuery);