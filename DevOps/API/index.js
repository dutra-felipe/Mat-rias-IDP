function getResponse(response){
    console.log(response);
    response.json().then(data => console.log(data));
  }
  
  let func = () => {
    console.log("teste");
  }
  
  let variavel = fetch("https://jsonplaceholder.typicode.com/todos/2")
      .then((response) => {
        response.json().then(data => console.log(data));
      }).catch((error) => {
        console.log(error);
      });
  
  async function getTodo(){
    try{
      let response = await fetch("https://jsonplaceholder.typicode.com/todos/1");
      let data = await response.json();
      console.log(data);
    } catch(error){
      console.log(error);
    }
  }
  
  getTodo();