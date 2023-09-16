/**
@param {Function} fn
@return {Function}
 */

var once = function(fn) {
    var w = 0 ; 
    return function(...args){
        if(w === 0){
            w = 1; 
            var z = fn(...args); 
            return z ; 
        }
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
