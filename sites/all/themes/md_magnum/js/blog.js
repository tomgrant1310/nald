$(window).load(function() {

	// Featured post slider
	$('.featured-post-slider').bxSlider({
		auto: false,
		mode: 'horizontal',
		pager: false,
		controls: true,
		nextText: '',
		prevText: ''
	});

});


// FitVids
$(".post-media").fitVids();