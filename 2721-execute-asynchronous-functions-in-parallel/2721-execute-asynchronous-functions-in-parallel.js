/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve , reject)=>{
        var arr = []; 
        var ct =0 ;
        functions.forEach(( fun , index )=>{
            fun().then((resp)=>{
                arr[index] = resp;
                ct++; 
                if(ct === functions.length ){
                     resolve(arr); 
                }
            }).catch(err=>{
                reject(err); 
            })
        })
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */