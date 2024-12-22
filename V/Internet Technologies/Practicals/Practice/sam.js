/**
 * Comments
 * 
 * // -> single line comments
 * /* * / -> multi line comments
*/

//  HTML background color change using jss
// document.body.style.backgroundColor = '#33ff';

// DOM manipulation using jquery
// first import api in html & then place your script/file after that
// use normally in js
// syntax =>  $(selector).action()

$('h1').css({
    'textAlign' : 'center',
    'fontSize':'50px'
});

$('h1').hide(500);
$('h1').show(5000);

// Text flickering & changing colors 
function blink_change() {
    let randomColor = '#' + Math.floor(Math.random()* 0xFFFFFF).toString(16);
    $('h1').fadeOut(1500);
    $('h1').fadeIn(1500, () => {
        $('h1').css("color", randomColor);
    });
}
setInterval(blink_change, 3500);

