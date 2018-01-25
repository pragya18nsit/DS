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


