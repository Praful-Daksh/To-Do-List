function turnon() {
  
  document.getElementById("main").style.backgroundColor = "yellow";
  document.getElementById("main").style.boxShadow =  "0 0 50px yellow";
document.getElementById("bulb").style.backgroundColor = "white";
}
function turnoff()
{
  console.log('turn off bulb');
  document.getElementById("main").style.backgroundColor ="white";
  document.getElementById("main").style.boxShadow ="none";
  document.getElementById("bulb").style.backgroundColor = "black";
}