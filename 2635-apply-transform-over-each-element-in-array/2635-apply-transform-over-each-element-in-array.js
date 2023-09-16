/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    var x = new Array() ; 
    arr.forEach((index ,val)=>{
        x.push(fn(index , val)); 
    })
    return x; 
};