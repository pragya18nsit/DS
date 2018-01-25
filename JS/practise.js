'use strict';

//require modules;

//fix for certificate issues

let eventHandler = function (context, req, config, config, requestAuditLogObj, performanceTimeHelper) {
	

	class MainClass(){
		constructor(){
			__this = this;
		}

		doMain(){
			return new Promise(function(resolve, reject){
					__this.stage = constants.stage;
					__this.countryCode;
					__this.salesOrgVal;
					__this.mandatoryFieldsObj = {};
					__this.dunsNumber;
					__this.mdm_id;
					__this.customermatchId;
					__this.customerMatchscore;
					__this.recordIdentification_internalID_array;
					__this.notesinternalid;
					__this.customerinfoobj = JSON.parse(JSON.stringify(constants.customerinfoobj));


					let response_200_promise = {
						status: 200,
						body:{
							response: 'OK',
							message: 'dlshc kjs hckjsh kjs hjs'
						}
					};


					let response_200_promise = {
						status: 200,
						body:{
							response: 'OK',
							message: 'dlshc kjs hckjsh kjs hjs'
						}
					};

					let response_200_promise = {
						status: 200,
						body:{
							response: 'OK',
							message: 'dlshc kjs hckjsh kjs hjs'
						}
					};

					let response_200_promise = {
						status: 200,
						body:{
							response: 'OK',
							message: 'dlshc kjs hckjsh kjs hjs'
						}
					};

					__this.dovalidations().then(function(data){
						requestAuditLogObj.request.userinfo = req.body.customercreationrequest.userinfo;

						return async.waterfall([
							__this.dummyforwaterfall(),
							__this.dodupcheck(),
							__this.createcustomer()
							],
							function(err, result){
									if(!err){
										if(__this.mdm_id){
											requestAuditLogObj.Response.NewIdCreated = __this.mdm_currentNumber;
											email_options = {
                                            	email_subject: '[' + process.env.ENV + '] [LEAN CUSTOMER] ' + 'Customer Creation Successful for Site Id: ' + __this.mdm_currentNumber,
                                            	email_body_title: 'Following customer created: ',
                                            	email_body_content: { response: result, request: req.body }
                                        	};	
										}
										else{
											requestAuditLogObj.Response.matchidscore = __this.score;
											requestAuditLogObj.Response.matchidfound = __this.matchid;
											//no email to be sent
										}
									}
									else{
										if(err){
											err = err.response;
											requestAuditLogObj.Response.err = err;
											let reason = constants.REASON;
											let reason_more;

											switch(__this.stage){
												case constants.sapmdm_stage:
													reason = constants.sapmdm_reason;
													break;
												case constants.sapecc_stage:
													reason = constants.sapecc_reason;
													break;
												default: // case constants.STAGES_AND_REASONS.preprocess.stage:
                                           			reason = constants.STAGES_AND_REASONS.preprocess.reason;  //Initial Preprocessing Failed.
                                            		break;
											}
											context_res_500_err.body.reason = reason + ' Please contact edmcustomer@ca.com';

											try{
												err = JSON.stringify(err);
											} catch(e){
											}

											if (err.includes(constants.ERR_NO_PER)) {
												return reject(context_res_500_err);
											}

											email_options = {
												email_subject  :'',
												email_body_title : '',
												email_body_content: ''
											}
										};

										if(email_options){
											if(isLocal){
												return doneProcessing();
											}
											__this.writetoservicebustopic();
											return doneProcessing();
										}
										else{
											return doneProcessing();
										}	

										function doneProcessing(){
											if(err)
												return reject(context_res_500_err);
											if(__this.mdm_id)
												return resolve(context_res_200_err)
											else
												return resolve(context_res_200_err_dups);
										}
									}
							})
					}).catch(function(err){
						requestAuditLogObj.Response.ErrorMessage = err;
						reject(response);
					});
			});
		}

		dummyforwaterfall(function){
			return callback(null, 'done');
		}

		dovalidations(){
			return new Promise((resolve, reject) => {
				return async.waterfall([
						__this.startDummy_for_waterfall,
						__this.domandatoryfields,
						__this.searchVTCustomerValidationRules,
						__this.inputValidations
				], function(err, result){
					if(err){
						return reject(err.response);
					}
					return resolve(result);
				})
			});
		}
	}

	domandatoryfields(prevResult, callback){
		if(!req.body  || !req.body.address){
			let err = "address "+ constants.NOTPRESENT;
			return callback(err);
		}
		return callback(null, done);
	}

	searchVT_CustomerValidationRules(prevResult, callback){
		request_body = __this.prepareSoapRequestBody();
		request_options = JSON.parse(JSON.stringify(config_MDM_OPTIONS));
		return __this.utilmakeRequest(context, request_body, request_options).then(function(xmlResponse){
			 let status =
                        __this.util_regex_getSoapXmlTagValues(
                            xmlResponse.response,
                            /<rn[0-9]:status>(.*)<\/rn[0-9]:status>/g,
                            [1]
                        );
             if(!status = 'OK'){
             	return callback(xmlResponse);
             }
             let AllBPSArray = extractcustommersearchVTValidationrulefromxmlResponse;
             //create the mandatory field obj 
             //fieldName: '',
             //defaultValue: '',
                                                     // fieldNameInput
             __this.mandatoryFieldsObj[constants.mdm_to_input_mapping[fieldName]] = true;
              if (!__this.salesOrgValue) {
              		return callback(err);
              }
              return callback(null, 'done');
			}).catch(function(err){
				return callback(err);
			});
	}

	validateInput(prevResult,callback){
		err = __this.validateMissingFields();
		if(err){
			return callback(err);
		}
		return callback(null, 'done');
	}

	validateFields(){
		let isforcecreate = req.body['customerCreationRequest']['isForceCreate'];
		if(isforcecreate === undefined){
			return err;
		}
		//loop the mandtory field object and check for Name1 and AccountGroupcode
		return '';
	}

	validateName1(reqBody){
		//do regex test
		if(err)
			return err;
		return '';
	}

	validateAccountGroupCode(reqBody){
		//do regex test
		if(err)
			return err;
		return '';
	}

	util_makeRequest(context, request_options, request_body, request_authorization, is_apikey) {
		return new Promise((resolve, reject)=>{
			if(is_apikey){
				request.headers.authorization = is_apike;
			}
			else{
				if (request_authorization) {
                        request_options.headers.Authorization = request_authorization;
                } else {
                    request_options.headers.Authorization = config.env.MDM_AUTHORIZATION; //g_decrypted;
                }
			}
			let request = https.request(request_options, function(res){
				let chunks = [];
                // request in progress
                res.on('data', function (data) {
                    chunks.push(data);
                });
                res.on('end', function(){
                	let buffer = Buffer.concat(chunks);
                    if (request_options.headers['Accept-Encoding'] !== 'gzip') {

                        let response = buffer.toString();
                        context.log.verbose('response');
                        context.log.verbose(response);
                        return resolve({ response: response });
                    }
                    zlib.gunzip(buffer, function (err, decoded) {
                    	return resolve({ response: decoded.toString(); });
                    });
                });
                res.on('error', function(e){
                	return reject(e);
                })
			})
			request.on('timeout', function(){
				return request.destroy();
			});
			request.on('error', function(){
				return request.destroy();
			})
			if(request_body){
				request.write(request_body);
			}
			request.end();
		});
	}

	getValueAtJsonPath(obj, jsonPathwithdots){
		// Example:
        // obj               = {a:{  b:{c: "c_value"}  }}
        // jsonPathWithDots  = "a.b.c"
        //      returns "c_value"

        let lastKey = '';
        jsonPathWithDots
            .split('.')
            .forEach(function (jsonKeyInPathL2R) {
                lastKey = jsonKeyInPathL2R;
                obj = obj[jsonKeyInPathL2R];
            });
        return { key: lastKey, val: obj };
	}

  // Function
    encodeXml(str1) {
        if (!str1) {
            return "";
        }

        return str1
            .replace(/&/g, '&amp;')
            .replace(/</g, '&lt;')
            .replace(/>/g, '&gt;')
            .replace(/"/g, '&quot;')
            .replace(/'/g, '&apos;');
    }

    //Compute the edit distance between the two given strings
    getEditDistance(a, b) {
    }
    
	(new MainClass()).doMain()
		.then(function(data){
			context.log("fjshv jdvhdv");
			context.log("fjshv jdvhdv");
			context.log("fjshv jdvhdv");
			context.log("fjshv jdvhdv");	
			context.log("fjshv jdvhdv");
			return context.done();
		})
		.catch(function(){
			context.log.error("dcuhjsdhcsd");
			context.log.error("dcuhjsdhcsd");
			context.log.error("dcuhjsdhcsd");
			context.log.error("dcuhjsdhcsd");
			return context.done();
		})

};//end of event handler

module.exports = {eventHandler: eventHandler};