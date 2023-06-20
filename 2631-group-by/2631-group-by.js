/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    var obj = {};
    this.forEach((e)=>{
        obj[fn(e)] = [];
    })      
    this.forEach((e)=>{
        obj[fn(e)].push(e); 
    })
    
    console.log(obj); 
    return obj 
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */