var addTwoPromises = function(promise1, promise2) {
    return new Promise((resolve, reject) => {
        promise1.then((val1) => {
            promise2.then((val2) => {
                resolve(val1 + val2);
            }).catch(reject);  // Handle the rejection of promise2
        }).catch(reject);  // Handle the rejection of promise1
    });
};
