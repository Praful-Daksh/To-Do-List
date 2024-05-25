var list = document.querySelector('ul');
var data = document.querySelector('input');
var sub = document.getElementById('sub');
var message = document.getElementById('msg');
var items = document.querySelector('li');

addItem = ()=>{
      console.log(data.value);
      var listItem = document.createElement('li');
  listItem.innerHTML= `${data.value} <button id="but" class="but">X</button>`;
  list.appendChild(listItem);
  message.innerText = `(${list.childElementCount}) items in List`;
}
deleteItem = (e)=>{
  if(e.target.classList.contains('but')){
    var item = e.target.parentElement;
    list.removeChild(item);
    message.innerText = `(${list.childElementCount}) items in List`;
    if(list.childElementCount==0){
      message.innerText=`(${list.childElementCount}) items in List`;
    }
  }
}

sub.addEventListener('click', addItem);
list.addEventListener('click',deleteItem);