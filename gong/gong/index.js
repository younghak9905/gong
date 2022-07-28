const {odd,even}=require('./var');
const checkNumber=require('./func');

function checkString0dd0rEven(str){
    if(str.length%2){
        return odd;
    }
    return even;

}
console.log(checkNumber(10));
console.log(checkString0dd0rEven('hello'));
