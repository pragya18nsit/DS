Function.prototype.bind = function(ctx) {
   	var fn = this;
    return function() {
        fn.apply(ctx, arguments);
    };
};

var obj = {
	key1: "value1"
}

var funca = function(){
	return this.key1 + "lskdjkljs lks";
}

var funcb = function(argument1){
	return this.key1  + "lskdjkljs lks" + argument1;
}


funca.call(obj);
funcb.call(obj, 'argumentsObj');

funca.apply(obj);
funcb.apply(obj,['argumentsObj']);

funca.bind(obj)();

1.async.parallel and promise.all do the same thing.The only thing is in async.parallel we use
	an external module
2.async.each we can pass multiple functions with same name and arguments and execute, in paarallel or waterfall they have to be sepeartae names.
