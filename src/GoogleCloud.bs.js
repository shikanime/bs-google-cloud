'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Js_dict = require("bs-platform/lib/js/js_dict.js");
var Js_json = require("bs-platform/lib/js/js_json.js");
var Js_option = require("bs-platform/lib/js/js_option.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");
var Js_null_undefined = require("bs-platform/lib/js/js_null_undefined.js");

var jsMapperConstantArray = [
  200,
  201,
  202,
  203,
  204,
  205,
  206,
  207,
  208,
  226,
  300,
  301,
  302,
  303,
  304,
  305,
  306,
  307,
  308,
  400,
  401,
  402,
  403,
  404,
  405,
  406,
  407,
  408,
  409,
  410,
  411,
  412,
  413,
  414,
  415,
  416,
  417,
  418,
  421,
  422,
  423,
  424,
  426,
  428,
  429,
  431,
  451,
  500,
  501,
  502,
  503,
  504,
  505,
  506,
  507,
  508,
  510,
  511
];

function tToJs(param) {
  return jsMapperConstantArray[param];
}

function tFromJs(param) {
  return Js_mapperRt.fromInt(58, jsMapperConstantArray, param);
}

var StatusCode = {
  tToJs: tToJs,
  tFromJs: tFromJs,
  fromInt: tFromJs,
  toInt: tToJs
};

var _map = {"Lax":"lax","Strict":"strict","None":"none"};

var _revMap = {"lax":"Lax","strict":"Strict","none":"None"};

function sameSiteToJs(param) {
  return _map[param];
}

function sameSiteFromJs(param) {
  return _revMap[param];
}

function filterKeys(obj) {
  return Js_dict.fromArray(Js_dict.entries(obj).filter(function (param) {
                  return !(param[1] == null);
                }));
}

function cookie(name, maxAge, expiresGMT, httpOnly, secure, signed, path, sameSite, domain, value, response) {
  response.cookie(name, value, filterKeys({
            maxAge: Js_null_undefined.fromOption(maxAge),
            expires: Js_null_undefined.fromOption(expiresGMT),
            path: Js_null_undefined.fromOption(path),
            httpOnly: Js_null_undefined.fromOption(httpOnly),
            secure: Js_null_undefined.fromOption(secure),
            sameSite: Js_null_undefined.fromOption(Js_option.map((function (x) {
                        return _map[x];
                      }), sameSite)),
            signed: Js_null_undefined.fromOption(signed),
            domain: Js_null_undefined.fromOption(domain)
          }));
  return response;
}

function clearCookie(name, httpOnly, secure, signed, pathOpt, sameSite, response) {
  var path = pathOpt !== undefined ? pathOpt : "/";
  response.clearCookie(name, filterKeys({
            maxAge: undefined,
            expires: undefined,
            path: path,
            httpOnly: Js_null_undefined.fromOption(httpOnly),
            secure: Js_null_undefined.fromOption(secure),
            sameSite: Js_null_undefined.fromOption(Js_option.map((function (x) {
                        return _map[x];
                      }), sameSite)),
            signed: Js_null_undefined.fromOption(signed)
          }));
  return response;
}

function sendStatus(statusCode) {
  var partial_arg = jsMapperConstantArray[statusCode];
  return function (param) {
    return param.sendStatus(partial_arg);
  };
}

function status(statusCode) {
  var partial_arg = jsMapperConstantArray[statusCode];
  return function (param) {
    return param.status(partial_arg);
  };
}

var $$Response = {
  StatusCode: StatusCode,
  sameSiteToJs: sameSiteToJs,
  sameSiteFromJs: sameSiteFromJs,
  filterKeys: filterKeys,
  cookie: cookie,
  clearCookie: clearCookie,
  sendStatus: sendStatus,
  status: status
};

function bodyText(req) {
  var body = req.body;
  if (Js_json.test(body, /* String */0)) {
    return body;
  }
  
}

function decodeStringDict(json) {
  return Js_option.andThen((function (obj) {
                var allStrings = $$Array.fold_left((function (prev, value) {
                        if (prev) {
                          return Js_json.test(value, /* String */0);
                        } else {
                          return false;
                        }
                      }), true, Js_dict.values(obj));
                if (allStrings) {
                  return Caml_option.some(obj);
                }
                
              }), Js_json.decodeObject(json));
}

function bodyURLEncoded(req) {
  return decodeStringDict(req.body);
}

function httpMethod(req) {
  var s = req.method;
  switch (s) {
    case "CONNECT" :
        return /* Connect */7;
    case "DELETE" :
        return /* Delete */3;
    case "GET" :
        return /* Get */0;
    case "HEAD" :
        return /* Head */4;
    case "OPTIONS" :
        return /* Options */5;
    case "PATCH" :
        return /* Patch */8;
    case "POST" :
        return /* Post */1;
    case "PUT" :
        return /* Put */2;
    case "TRACE" :
        return /* Trace */6;
    default:
      return Pervasives.failwith("Express.Request.method_ Unexpected method: " + s);
  }
}

function protocol(req) {
  var s = req.protocol;
  switch (s) {
    case "http" :
        return /* Http */0;
    case "https" :
        return /* Https */1;
    default:
      return Pervasives.failwith("Express.Request.protocol, Unexpected protocol: " + s);
  }
}

function accepts(types, req) {
  var ret = req.accepts(types);
  var tagged_t = Js_json.classify(ret);
  if (typeof tagged_t === "number" || tagged_t.TAG) {
    return ;
  } else {
    return tagged_t._0;
  }
}

function acceptsCharsets(types, req) {
  var ret = req.acceptsCharsets(types);
  var tagged_t = Js_json.classify(ret);
  if (typeof tagged_t === "number" || tagged_t.TAG) {
    return ;
  } else {
    return tagged_t._0;
  }
}

var $$Request = {
  bodyText: bodyText,
  decodeStringDict: decodeStringDict,
  bodyURLEncoded: bodyURLEncoded,
  httpMethod: httpMethod,
  protocol: protocol,
  accepts: accepts,
  acceptsCharsets: acceptsCharsets
};

var Http = {
  $$Response: $$Response,
  $$Request: $$Request
};

var Background = {};

var $$Function = {
  Http: Http,
  Background: Background
};

var DownloadOption = {};

var MetadataOption = {};

var $$File = {};

var GetFileOption = {};

var UploadOption = {};

var Bucket = {};

var $$Storage = {
  DownloadOption: DownloadOption,
  MetadataOption: MetadataOption,
  $$File: $$File,
  GetFileOption: GetFileOption,
  UploadOption: UploadOption,
  Bucket: Bucket
};

var Duration = {};

var Message = {};

var Subscription = {};

var ExpirationPolicy = {};

var Topic = {};

var CreateSubscriptionRequest = {};

var DeadLetterPolicy = {};

var PubSub = {
  Duration: Duration,
  Message: Message,
  Subscription: Subscription,
  ExpirationPolicy: ExpirationPolicy,
  Topic: Topic,
  CreateSubscriptionRequest: CreateSubscriptionRequest,
  DeadLetterPolicy: DeadLetterPolicy
};

exports.$$Function = $$Function;
exports.$$Storage = $$Storage;
exports.PubSub = PubSub;
/* No side effect */
