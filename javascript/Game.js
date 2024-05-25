var question = 'Who came First : Egg or Chicken';
var egg = '<img src="ban.jpg" alt ="win" class ="img"/>';

var input = prompt(question);
console.log(input);
var confirmation = confirm('Are you sure');
for (var i = 0; i < 2; i++) {
  if (confirmation) {
    if (input != 'EGG' || 'egg') {
      var confirme = confirm('Wrong Try Again ?');
      if (confirme) {
        input = prompt(question);
      }
    }
    else {
      document.write(egg);
    }
  }
  else {
    input = prompt(question, input);
  }
}