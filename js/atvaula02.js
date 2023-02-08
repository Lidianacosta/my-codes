const nome_completo = prompt("digite seu nome completo:");
const data_nascimento = prompt("digite o ano em que nasceu:");
let salario_mensal = prompt("digite quanto voce recebe por mes:");
let quantos_filhos = prompt("digite quantos filhos tem:");

let idade = 2022 - data_nascimento;

let ate_se_aposentar = (salario_mensal *12) * (70 - idade);

if(quantos_filhos != 0){
    let dividir = ate_se_aposentar/quantos_filhos;

    console.log(`ola,${nome_completo}, tudo bem ?\n voce tem ${idade} de idade,seu salario e R$${salario_mensal} e recebera R$${ate_se_aposentar} ate se aposentar.\n caso voce deseje dividir seu salario entre seus filhos, dara ${dividir}para cada um.\n`);

    alert(`ola,${nome_completo}, tudo bem ?\n voce tem ${idade} de idade,seu salario e R$${salario_mensal} e recebera R$${ate_se_aposentar} ate se aposentar.\n caso voce deseje dividir seu salario entre seus filhos, dara ${dividir} para cada um.\n`);

}else{
    let dividir = "voce nao tem filhos pra devidir";

    console.log(`ola,${nome_completo}, tudo bem ?\n voce tem ${idade} de idade,seu salario e R$${salario_mensal} e recebera R$${ate_se_aposentar} ate se aposentar.\n caso voce deseje dividir seu salario entre seus filhos, dara ${dividir} para cada um.\n`);

    alert(`ola,${nome_completo}, tudo bem ?\n voce tem ${idade} de idade,seu salario e R$${salario_mensal} e recebera R$${ate_se_aposentar} ate se aposentar.\n caso voce deseje dividir seu salario entre seus filhos, ${dividir}.\n`);

}
