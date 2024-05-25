function toggleon() {
  /*var triangles = document.getElementsByClassName("triangle-3");
  for (var i = 0; i < triangles.length; i++) {
    triangles[i].style.backgroundColor = "black";
  }

  var squares = document.getElementsByClassName("triangle-4");
  for (var j = 0; j < squares.length; j++) {
    squares[j].style.backgroundColor = "black";
  }
  var multiple = document.getElementsByClassName("triangle-footer-1");
  
  for (var k = 0; k < multiple.length; k++) {
    multiple[k].style.backgroundColor = "black";
  }*/
  document.querySelector("body").style.backgroundColor = "black";
  document.getElementsByClassName("triangle3").style.borderBottomColor="black";
}

function toggleoff() {/*
  var triangles = document.getElementsByClassName("triangle-3");
  for (var i = 0; i < triangles.length; i++) {
    triangles[i].style.backgroundColor = "white";
  }

  var squares = document.getElementsByClassName("triangle-4");
  for (var j = 0; j < squares.length; j++) {
    squares[j].style.backgroundColor = "white";
  }*/

  document.querySelector("body").style.backgroundColor = "white";
}