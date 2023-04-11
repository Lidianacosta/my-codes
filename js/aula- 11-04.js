
const nums = prompt(`digitar uma lista de números separados por vírgula de 0 a 9.`); 

numeros = [];
console.log(numeros);

for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== ',') {
        numeros.push(parseInt(nums[i]));
    }
}
let soma = 0;
const pares = [];
const impar = [];
for (let i = 0; i < numeros.length; i++) {
    if (numeros[i] > 3 && numeros[i] <= 9) {
        soma += numeros[i];
    }
    if(numeros[i] % 2 === 0){
        pares.push(numeros[i]);
        console.log(`par: ${numeros[i]}`);
    }else{
        impar.push(numeros[i]);
        console.log(`impar: ${numeros[i]}`);
    }
}

console.log(`a soma dos valores (3,9] ${soma}`);
console.log(``);
const nums = prompt(`digitar uma lista de números separados por vírgula de 0 a 9.`); 

numeros = [];
console.log(numeros);

for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== ',') {
        numeros.push(parseInt(nums[i]));
    }
}
let soma = 0;
const pares = [];
const impar = [];
for (let i = 0; i < numeros.length; i++) {
    if (numeros[i] > 3 && numeros[i] <= 9) {
        soma += numeros[i];
    }
    if(numeros[i] % 2 === 0){
        pares.push(numeros[i]);
        console.log(`par: ${numeros[i]}`);
    }else{
        impar.push(numeros[i]);
        console.log(`impar: ${numeros[i]}`);
    }
}

console.log(`a soma dos valores (3,9] ${soma}`);
console.log(``);
