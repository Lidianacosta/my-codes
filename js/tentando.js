console.log("Hello, World!");

console.log('Hello, World!');

console.log(`Hello, World!`);

console.log(2023);

alert("Esse e um Alerta ");



let nomedalet = 10;

{
   nomedalet  = 11;
    //let nomedalet = 11; 
console.log(nomedalet);
}
console.log(nomedalet);

var nomedavar = 10;

{
    nomedavar  = 11;
   // var nomedavar = 11; 
console.log(nomedavar);
}
console.log(nomedavar);

const nomedaconst = "lidiana";
{
    
   //const nomedaconst = "lidianacosta"; 
console.log(nomedaconst);
}
console.log(nomedaconst);

undefined
let var1 = undefined;
console.log(var1);
let var2;
console.log(var2);

// boolean
let var3 = true;
console.log(var3);
let var4 = false;
console.log(var4);

//String
var5 = "lidiana"

//Number
let var6 = 10;
let var7 = 10.1;

console.log(typeof(var7),var7);

console.log("o tipo da variavel  "  + var7 + " eh " +  typeof(var7));
alert("o tipo da variavel  "  + var7 + " eh " +  typeof(var7));

console.log(`o tipo da variavel ${var7} he ${typeof(var7)}`);


let nome = prompt("digite seu nome");
console.log(nome);

==============================================================================================================================

const primeironome = prompt("diga seu primeiro nome: ");
const sobrenome = prompt("digite seu sobrenome ");
const idade = prompt("digite sua idade: ");
const id = Math.floor(Math.random()* 100);
const id_1= parseInt(Math.random()* 100);

console.log(`seu primeiro nome e ${primeironome} ${sobrenome}\n sua idade ${idade}\n seu id e ${id}\n seu id.1 e ${id_1}\n`);
alert(`seu primeiro nome e ${primeironome} ${sobrenome}\n sua idade ${idade}\n seu id e ${id}\n seu id.1 e ${id_1}\n`);

let idade = "22" ;
let nova_idade_i = parseInt(idade);
let nova_idade_f = parseFloat(idade);

console.log(typeof(nova_idade_i));
console.log(typeof(nova_idade_f));

let salario = 1000;
let novo_salario = salario.toString(10);
console.log(salario.toFixed(2));
console.log(typeof(novo_salario));
console.log(novo_salario);

let a = 10;
let b = 18;

let mul = a * b;

alert(mul);

=======================================================================================================================
  
   const nomecompleto = prompt("digite seu nome completo");
const anodenascimento = parseInt(prompt("digite o ano de nascimentto"));
const salariomensal = parseFloat(prompt("digite seu salario mensal em reais: R$ "));
const qtdfilhos = parseInt(prompt("digite a quantidade de filhos que voce tem: "));
const idade = 2023 - anodenascimento;
const  ate_se_aposentar = (salariomensal *12) * (70 - idade);

 
if(qtdfilhos!=0){
    const dividir = parseFloat(salariomensal/qtdfilhos);

    console.log(`ola,${nomecompleto}, tudo bem ?\n voce tem ${idade} de idade,seu salario e R$${salariomensal.toFixed(2)} e recebera R$${ate_se_aposentar.toFixed(2)} ate se aposentar.\n caso voce deseje dividir seu salario entre seus filhos, dara ${dividir} para cada um.\n`);

    alert(`ola,${nomecompleto}, tudo bem ?\n voce tem ${idade} de idade,seu salario e R$${salariomensal.toFixed(2)} e recebera R$${ate_se_aposentar.toFixed(2)} ate se aposentar.\n caso voce deseje dividir seu salario entre seus filhos, ${dividir}.\n`);

}else{
    const dividir = "voce nao tem filho";

    console.log(`ola,${nomecompleto}, tudo bem ?\n voce tem ${idade} de idade,seu salario e R$${salariomensal.toFixed(2)} e recebera R$${ate_se_aposentar.toFixed(2)} ate se aposentar.\n caso voce deseje dividir seu salario entre seus filhos,${dividir}.\n`);

    alert(`ola,${nomecompleto}, tudo bem ?\n voce tem ${idade} de idade,seu salario e R$${salariomensal.toFixed(2)} e recebera R$${ate_se_aposentar.toFixed(2)} ate se aposentar.\n caso voce deseje dividir seu salario entre seus filhos, ${dividir}.\n`);
}

==========================================================================================================================================================================================================================================================================================
   
   
