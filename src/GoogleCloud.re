module Function = {
  module Http = {
    type complete;

    module Response = {
      type t;
      module StatusCode = {
        [@bs.deriving jsConverter]
        type t =
          | [@bs.as 200] Ok
          | [@bs.as 201] Created
          | [@bs.as 202] Accepted
          | [@bs.as 203] NonAuthoritativeInformation
          | [@bs.as 204] NoContent
          | [@bs.as 205] ResetContent
          | [@bs.as 206] PartialContent
          | [@bs.as 207] MultiStatus
          | [@bs.as 208] AleadyReported
          | [@bs.as 226] IMUsed
          | [@bs.as 300] MultipleChoices
          | [@bs.as 301] MovedPermanently
          | [@bs.as 302] Found
          | [@bs.as 303] SeeOther
          | [@bs.as 304] NotModified
          | [@bs.as 305] UseProxy
          | [@bs.as 306] SwitchProxy
          | [@bs.as 307] TemporaryRedirect
          | [@bs.as 308] PermanentRedirect
          | [@bs.as 400] BadRequest
          | [@bs.as 401] Unauthorized
          | [@bs.as 402] PaymentRequired
          | [@bs.as 403] Forbidden
          | [@bs.as 404] NotFound
          | [@bs.as 405] MethodNotAllowed
          | [@bs.as 406] NotAcceptable
          | [@bs.as 407] ProxyAuthenticationRequired
          | [@bs.as 408] RequestTimeout
          | [@bs.as 409] Conflict
          | [@bs.as 410] Gone
          | [@bs.as 411] LengthRequired
          | [@bs.as 412] PreconditionFailed
          | [@bs.as 413] PayloadTooLarge
          | [@bs.as 414] UriTooLong
          | [@bs.as 415] UnsupportedMediaType
          | [@bs.as 416] RangeNotSatisfiable
          | [@bs.as 417] ExpectationFailed
          | [@bs.as 418] ImATeapot
          | [@bs.as 421] MisdirectedRequest
          | [@bs.as 422] UnprocessableEntity
          | [@bs.as 423] Locked
          | [@bs.as 424] FailedDependency
          | [@bs.as 426] UpgradeRequired
          | [@bs.as 428] PreconditionRequired
          | [@bs.as 429] TooManyRequests
          | [@bs.as 431] RequestHeaderFieldsTooLarge
          | [@bs.as 451] UnavailableForLegalReasons
          | [@bs.as 500] InternalServerError
          | [@bs.as 501] NotImplemented
          | [@bs.as 502] BadGateway
          | [@bs.as 503] ServiceUnavailable
          | [@bs.as 504] GatewayTimeout
          | [@bs.as 505] HttpVersionNotSupported
          | [@bs.as 506] VariantAlsoNegotiates
          | [@bs.as 507] InsufficientStorage
          | [@bs.as 508] LoopDetected
          | [@bs.as 510] NotExtended
          | [@bs.as 511] NetworkAuthenticationRequired;
        let fromInt = tFromJs;
        let toInt = tToJs;
      };
      [@bs.send.pipe: t]
      external cookie_ : (string, Js.Json.t, 'a) => unit = "cookie";
      [@bs.send.pipe: t]
      external clearCookie_ : (string, 'a) => unit = "clearCookie";
      [@bs.deriving jsConverter]
      type sameSite = [ | [@bs.as "lax"] `Lax | [@bs.as "strict"] `Strict | [@bs.as "none"] `None];
      external toDict : 'a => Js.Dict.t(Js.nullable('b)) = "%identity";
      let filterKeys = obj => {
        let result = toDict(obj);
        result
        |> Js.Dict.entries
        |> Js.Array.filter(((_key, value)) => ! Js.Nullable.isNullable(value))
        |> Js.Dict.fromArray;
      };
      let cookie =
          (
            ~name,
            ~maxAge=?,
            ~expiresGMT=?,
            ~httpOnly=?,
            ~secure=?,
            ~signed=?,
            ~path=?,
            ~sameSite: option(sameSite)=?,
            ~domain=?,
            value,
            response,
          ) => {
        cookie_(
          name,
          value,
          {
            "maxAge": maxAge |> Js.Nullable.fromOption,
            "expires": expiresGMT |> Js.Nullable.fromOption,
            "path": path |> Js.Nullable.fromOption,
            "httpOnly": httpOnly |> Js.Nullable.fromOption,
            "secure": secure |> Js.Nullable.fromOption,
            "sameSite":
              sameSite
              |> Js.Option.map((. x) => sameSiteToJs(x))
              |> Js.Nullable.fromOption,
            "signed": signed |> Js.Nullable.fromOption,
            "domain": domain |> Js.Nullable.fromOption,
          }
          |> filterKeys,
          response,
        );
        response;
      };
      let clearCookie =
          (
            ~name,
            ~httpOnly=?,
            ~secure=?,
            ~signed=?,
            ~path="/",
            ~sameSite: option(sameSite)=?,
            response,
          ) => {
        clearCookie_(
          name,
          {
            "maxAge": Js.Nullable.undefined,
            "expires": Js.Nullable.undefined,
            "path": path,
            "httpOnly": httpOnly |> Js.Nullable.fromOption,
            "secure": secure |> Js.Nullable.fromOption,
            "sameSite":
              sameSite
              |> Js.Option.map((. x) => sameSiteToJs(x))
              |> Js.Nullable.fromOption,
            "signed": signed |> Js.Nullable.fromOption,
          }
          |> filterKeys,
          response,
        );
        response;
      };
      [@bs.send.pipe: t] external sendFile : (string, 'a) => complete = "sendFile";
      [@bs.send.pipe: t] external sendString : string => complete = "send";
      [@bs.send.pipe: t] external sendJson : Js.Json.t => complete = "json";
      [@bs.send.pipe: t] external sendBuffer : Node.Buffer.t => complete = "send";
      [@bs.send.pipe: t] external sendArray : array('a) => complete = "send";
      [@bs.send.pipe: t] external sendRawStatus : int => complete = "sendStatus";
      let sendStatus = statusCode => sendRawStatus(StatusCode.toInt(statusCode));
      [@bs.send.pipe: t] external rawStatus : int => t = "status";
      let status = statusCode => rawStatus(StatusCode.toInt(statusCode));
      [@bs.send.pipe: t] [@ocaml.deprecated "Use sendJson instead`"]
      external json : Js.Json.t => complete = "json";
      [@bs.send.pipe: t]
      external redirectCode : (int, string) => complete = "redirect";
      [@bs.send.pipe: t] external redirect : string => complete = "redirect";
      [@bs.send.pipe: t] external setHeader : (string, string) => t = "set";
      [@bs.send.pipe: t] external setType : (string) => t = "type";
      [@bs.send.pipe: t] external setLinks : Js.Dict.t(string) => t = "links";
      [@bs.send.pipe: t] external end_ : complete = "end";
      [@bs.send.pipe: t] external render: (string, Js.Dict.t(string), 'a) => complete = "render";
    };

    module Request = {
      type t;
      type params = Js_dict.t(Js_json.t);
      [@bs.get] external params : t => params = "params";

      /*** [params request] return the JSON object filled with the
           request parameters */
      external asJsonObject : t => Js_dict.t(Js_json.t) = "%identity";

      /*** [asJsonObject request] casts a [request] to a JSON object. It is
           common in Express application to use the Request object as a
          placeholder to maintain state through the various middleware which
          are executed. */
      [@bs.get] external baseUrl : t => string = "baseUrl";
      [@bs.get] external body_ : t => 'a = "body";

      /*** When using the json body-parser middleware and receiving a request with a
           content type of "application/json", this property is a Js.Json.t that
          contains the body sent by the request. **/
      [@bs.get] [@bs.return null_undefined_to_opt]
      external bodyJSON : t => option(Js.Json.t) = "body";

      /*** When using the raw body-parser middleware and receiving a request with a
           content type of "application/octet-stream", this property is a
          Node_buffer.t that contains the body sent by the request. **/
      [@bs.get] [@bs.return null_undefined_to_opt]
      external bodyRaw : t => option(Node.Buffer.t) = "body";

      /*** When using the text body-parser middleware and receiving a request with a
           content type of "text/plain", this property is a string that
          contains the body sent by the request. **/
      let bodyText: t => option(string) =
        req => {
          let body: string = body_(req);
          if (Js.Json.test(body, Js.Json.String)) {
            Some(body);
          } else {
            None;
          };
        };
      let decodeStringDict = json =>
        Js.Json.decodeObject(json)
        |> Js.Option.andThen((. obj) => {
            let source: Js.Dict.t(string) = Obj.magic(obj);
            let allStrings =
              Js.Dict.values(source)
              |> Array.fold_left(
                    (prev, value) => prev && Js.Json.test(value, Js.Json.String),
                    true,
                  );
            if (allStrings) {
              Some(source);
            } else {
              None;
            };
          });
      let bodyURLEncoded: t => option(Js.Dict.t(string)) =
        req => {
          let body: Js.Json.t = body_(req);
          decodeStringDict(body);
        };

      /*** When using the urlencoded body-parser middleware and receiving a request
           with a content type of "application/x-www-form-urlencoded", this property
          is a Js.Dict.t string that contains the body sent by the request. **/
      [@bs.get] [@bs.return null_undefined_to_opt]
      external cookies : t => option(Js.Dict.t(Js.Json.t)) = "cookies";

      /*** When using cookie-parser middleware, this property is an object
           that contains cookies sent by the request. If the request contains
          no cookies, it defaults to {}.*/
      [@bs.get] [@bs.return null_undefined_to_opt]
      external signedCookies : t => option(Js.Dict.t(Js.Json.t)) = "signedCookies";

      /*** When using cookie-parser middleware, this property contains signed cookies
           sent by the request, unsigned and ready for use. Signed cookies reside in
          a different object to show developer intent; otherwise, a malicious attack
          could be placed on req.cookie values (which are easy to spoof).
          Note that signing a cookie does not make it “hidden” or encrypted;
          but simply prevents tampering (because the secret used to
          sign is private). **/
      [@bs.get] external hostname : t => string = "hostname";

      /*** [hostname request] Contains the hostname derived from the Host
           HTTP header.*/
      [@bs.get] external ip : t => string = "ip";

      /*** [ip request] Contains the remote IP address of the request.*/
      [@bs.get] external fresh : t => bool = "fresh";

      /*** [fresh request] returns [true] whether the request is "fresh" */
      [@bs.get] external stale : t => bool = "stale";

      /*** [stale request] returns [true] whether the request is "stale"*/
      [@bs.get] external methodRaw : t => string = "method";
      type httpMethod =
        | Get
        | Post
        | Put
        | Delete
        | Head
        | Options
        | Trace
        | Connect
        | Patch;
      let httpMethod: t => httpMethod =
        req =>
          switch (methodRaw(req)) {
          | "GET" => Get
          | "POST" => Post
          | "PUT" => Put
          | "PATCH" => Patch
          | "DELETE" => Delete
          | "HEAD" => Head
          | "OPTIONS" => Options
          | "TRACE" => Trace
          | "CONNECT" => Connect
          | s => failwith("Express.Request.method_ Unexpected method: " ++ s)
          };

      /*** [method_ request] return a string corresponding to the HTTP
           method of the request: GET, POST, PUT, and so on */
      [@bs.get] external originalUrl : t => string = "originalUrl";

      /*** [originalUrl request] returns the original url. See
           https://expressjs.com/en/4x/api.html#req.originalUrl */
      [@bs.get] external path : t => string = "path";

      /*** [path request] returns the path part of the request URL.*/
      type protocol =
        | Http
        | Https;
      let protocol: t => protocol =
        req => {
          module Raw = {
            [@bs.get] external protocol : t => string = "protocol";
          };
          switch (Raw.protocol(req)) {
          | "http" => Http
          | "https" => Https
          | s => failwith("Express.Request.protocol, Unexpected protocol: " ++ s)
          };
        };

      /*** [protocol request] returns the request protocol string: either http
           or (for TLS requests) https. */
      [@bs.get] external secure : t => bool = "secure";

      /*** [secure request] returns [true] if a TLS connection is established */
      [@bs.get] external query : t => Js.Dict.t(Js.Json.t) = "query";

      /*** [query request] returns an object containing a property for each
           query string parameter in the route. If there is no query string,
          it returns the empty object, {} */
      let accepts: (array(string), t) => option(string) =
        (types, req) => {
          module Raw = {
            [@bs.send]
            external accepts : (t, array(string)) => Js.Json.t = "accepts";
          };
          let ret = Raw.accepts(req, types);
          let tagged_t = Js_json.classify(ret);
          switch (tagged_t) {
          | JSONString(x) => Some(x)
          | _ => None
          };
        };

      /*** [acceptsRaw accepts types] checks if the specified content types
           are acceptable, based on the request's Accept HTTP header field.
          The method returns the best match, or if none of the specified
          content types is acceptable, returns [false] */
      let acceptsCharsets: (array(string), t) => option(string) =
        (types, req) => {
          module Raw = {
            [@bs.send]
            external acceptsCharsets : (t, array(string)) => Js.Json.t =
              "acceptsCharsets";
          };
          let ret = Raw.acceptsCharsets(req, types);
          let tagged_t = Js_json.classify(ret);
          switch (tagged_t) {
          | JSONString(x) => Some(x)
          | _ => None
          };
        };
      [@bs.send.pipe: t] [@bs.return null_undefined_to_opt]
      external get : string => option(string) = "get";

      /*** [get return field] returns the specified HTTP request header
           field (case-insensitive match) */
      [@bs.get] external xhr : t => bool = "xhr";
      /*** [xhr request] returns [true] if the request’s X-Requested-With
           header field is "XMLHttpRequest", indicating that the request was
          issued by a client library such as jQuery */
    };
  };

  module Background = {
    type context = {
      eventId: string,
      timestamp: string,
      eventType: string,
      resource: string,
    };
    type event = {
      data: string,
      attributes: Js.Dict.t(string),
      messageId: string,
      publishTime: string,
    };

    type file = {
      bucket: string,
      contentType: string,
      crc32c: string,
      etag: string,
      md5hash: string,
      generation: string,
      kind: string,
      mediaLink: string,
      metageneration: string,
      name: string,
      selfLink: string,
      size: string,
      storageClass: string,
      timeCreated: string,
      updated: string,
    };
  };
};

module Storage = {
  type t;

  module DownloadOption = {
    type t;

    [@bs.obj]
    external make: (~destination: string=?, ~userProject: string=?, unit) => t;
  };

  module MetadataOption = {
    type t;

    [@bs.obj] external make: (~userProject: string=?, unit) => t;
  };

  module File = {
    type t;

    type fileData = {
      bucket: string,
      contentType: option(string),
      crc32c: string,
      etag: string,
      md5hash: string,
      generation: string,
      kind: string,
      mediaLink: string,
      metageneration: string,
      name: string,
      selfLink: string,
      size: string,
      storageClass: string,
      timeCreated: string,
      updated: string,
      md5Hash: string,
      timeStorageClassUpdated: string,
      metadata: Js.Dict.t(string),
    };

    type fileResponse('a, 'b) = (fileData, 'b);

    [@bs.send] external get: t => Js.Promise.t(fileResponse('a, 'b)) = "get";

    [@bs.send] external download: t => Js.Promise.t(Buffer.t) = "download";

    [@bs.send]
    external downloadWithOption: (t, DownloadOption.t) => Js.Promise.t(unit) =
      "download";

    [@bs.send]
    external createReadStream: t => 'a = "createReadStream";

    [@bs.send]
    external createWriteStream: t => 'a = "createWriteStream";

    type fileMetadataResponse('b) = (fileData, 'b);

    [@bs.send]
    external getMetadata: t => Js.Promise.t(fileMetadataResponse({..})) =
      "getMetadata";

    [@bs.send]
    external getMetadataWithOption:
      (t, MetadataOption.t) => Js.Promise.t(fileMetadataResponse({..})) =
      "getMetadata";
  };

  module GetFileOption = {
    type t;

    [@bs.obj]
    external make:
      (
        ~autoPaginate: bool=?,
        ~delimiter: string=?,
        ~directory: string=?,
        ~prefix: string=?,
        ~maxApiCalls: string=?,
        ~maxResults: int=?,
        ~pageToken: string=?,
        ~userProject: string=?,
        ~versions: bool=?,
        unit
      ) =>
      t;
  };

  module UploadOption = {
    type t;

    [@bs.obj]
    external make: (~gzip: bool=?, ~userProject: string=?, unit) => t;
  };

  module Bucket = {
    type t;

    [@bs.send] external delete: t => Js.Promise.t(unit) = "delete";

    [@bs.send] external setMetadata: t => Js.Promise.t(unit) = "setMetadata";

    [@bs.send]
    external setMetadataWithOption:
      (t, MetadataOption.t) => Js.Promise.t(unit) =
      "setMetadata";

    type bucketMetadataResponse('a, 'b) = ('a, 'b);

    [@bs.send]
    external getMetadata:
      t => Js.Promise.t(bucketMetadataResponse({..}, {..})) =
      "getMetadata";

    [@bs.send]
    external getMetadataWithOption:
      (t, MetadataOption.t) =>
      Js.Promise.t(bucketMetadataResponse({..}, {..})) =
      "getMetadata";

    type filesResponse('a) = (array(File.t), Js.Dict.t('a));

    [@bs.send]
    external getFiles: t => Js.Promise.t(filesResponse({..})) = "getFiles";

    [@bs.send]
    external getFilesWithOption:
      (t, GetFileOption.t) => Js.Promise.t(filesResponse({..})) =
      "getFiles";

    [@bs.send] external file: (t, string) => File.t = "file";

    [@bs.send] external upload: (t, string) => Js.Promise.t(unit) = "upload";

    [@bs.send]
    external uploadWithOption:
      (t, string, UploadOption.t) => Js.Promise.t(unit) =
      "upload";
  };

  [@bs.new] [@bs.module "@google-cloud/storage"]
  external make: unit => t = "Storage";

  type bucketsResponse('a) = (array(Bucket.t), 'a);

  [@bs.send]
  external getBuckets: t => Js.Promise.t(bucketsResponse({..})) =
    "getBuckets";

  [@bs.send] external bucket: (t, string) => Bucket.t = "bucket";

  [@bs.send] external createBucket: t => Js.Promise.t(unit) = "createBucket";
};

module PubSub = {
  type t;

  [@bs.new] [@bs.module "@google-cloud/pubsub"]
  external make: unit => t = "PubSub";

  module Duration = {
    type t;

    [@bs.module "@google-cloud/pubsub"]
    [@bs.scope ("protos", "google", "protobuf", "Duration")]
    external fromObject: Js.t({..}) => t = "fromObject";
  };

  module Message = {
    type t('a) = {
      id: string,
      ackId: string,
      data: 'a,
      attributes: Js.Json.t,
      publishTime: string,
    };

    [@bs.send] external ack: t('a) => unit = "ack";
  };

  module Subscription = {
    type t;

    [@bs.send]
    external onMessage:
      (t, [@bs.as "message"] _, Message.t('a) => unit) => unit =
      "on";

    [@bs.send] external delete: t => Js.Promise.t(unit) = "delete";
  };

  module ExpirationPolicy = {
    type t;

    [@bs.obj] external make: (~ttl: Duration.t, unit) => t;
  };

  module Topic = {
    type t;

    [@bs.send]
    external publish: (t, Node.Buffer.t) => Js.Promise.t(unit) = "publish";

    [@bs.send]
    external publishJson: (t, Js.Json.t) => Js.Promise.t(unit) =
      "publishJSON";

    [@bs.send]
    external publishJsonWithAttributes:
      (t, Js.Json.t, Js.Dict.t(string)) => Js.Promise.t(unit) =
      "publishJSON";
  };

  type subscriptionResponse('a) = (Subscription.t, Js.t('a));

  [@bs.send]
  external createSubscription:
    (t, string) => Js.Promise.t(subscriptionResponse({..})) =
    "createSubscription";

  module CreateSubscriptionRequest = {
    type t;

    [@bs.obj]
    external make:
      (
        ~deadLetterPolicy: string=?,
        ~flowControl: Js.Dict.t({..})=?,
        ~gaxOpts: Js.Dict.t({..})=?,
        ~messageRetentionDuration: int=?,
        ~pushEndpoint: string=?,
        ~retainAckedMessages: bool=?,
        ~expirationPolicy: ExpirationPolicy.t=?,
        unit
      ) =>
      t;
  };

  [@bs.send]
  external createSubscriptionWithOption:
    (t, string, CreateSubscriptionRequest.t) =>
    Js.Promise.t(subscriptionResponse({..})) =
    "createSubscription";

  type topicResponse('a) = (Topic.t, Js.t('a));

  [@bs.send]
  external createTopic: (t, string) => topicResponse({..}) = "createTopic";

  [@bs.send]
  external createTopicWithOption:
    (t, string, Js.Dict.t({..})) => topicResponse({..}) =
    "createTopic";

  module DeadLetterPolicy = {
    type t;

    [@bs.obj] external make: unit => t;
  };

  [@bs.send]
  external subscription: (t, string) => Subscription.t = "subscription";

  [@bs.send] external topic: (t, string) => Topic.t = "topic";
};
