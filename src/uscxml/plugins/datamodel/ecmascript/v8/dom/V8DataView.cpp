#include "V8ArrayBuffer.h"
#include "V8ArrayBufferView.h"
#include "V8DataView.h"

namespace Arabica {
namespace DOM {

v8::Persistent<v8::FunctionTemplate> V8DataView::Tmpl;
v8::Persistent<v8::FunctionTemplate> V8DataView::Constr;

v8::Handle<v8::Value> V8DataView::constructor(const v8::Arguments& args) {
	if (!args.IsConstructCall())
		return v8::ThrowException(v8::String::New("Cannot call constructor as function"));

	uscxml::DataView* localInstance = NULL;
	if (false) {
	} else if (args.Length() == 3 &&
	           args[0]->IsObject() && V8ArrayBuffer::hasInstance(args[0]) &&
	           args[1]->IsUint32() &&
	           args[2]->IsUint32()) {

		uscxml::ArrayBuffer* localBuffer = V8DOM::toClassPtr<V8ArrayBuffer::V8ArrayBufferPrivate >(args[0]->ToObject()->GetInternalField(0))->nativeObj;
		unsigned long localByteOffset = args[1]->ToNumber()->Uint32Value();
		unsigned long localByteLength = args[2]->ToNumber()->Uint32Value();
		localInstance = new uscxml::DataView(localBuffer, localByteOffset, localByteLength);

	} else if (args.Length() == 2 &&
	           args[0]->IsObject() && V8ArrayBuffer::hasInstance(args[0]) &&
	           args[1]->IsUint32()) {

		uscxml::ArrayBuffer* localBuffer = V8DOM::toClassPtr<V8ArrayBuffer::V8ArrayBufferPrivate >(args[0]->ToObject()->GetInternalField(0))->nativeObj;
		unsigned long localByteOffset = args[1]->ToNumber()->Uint32Value();
		localInstance = new uscxml::DataView(localBuffer, localByteOffset);

	} else if (args.Length() == 1 &&
	           args[0]->IsObject() && V8ArrayBuffer::hasInstance(args[0])) {

		uscxml::ArrayBuffer* localBuffer = V8DOM::toClassPtr<V8ArrayBuffer::V8ArrayBufferPrivate >(args[0]->ToObject()->GetInternalField(0))->nativeObj;
		localInstance = new uscxml::DataView(localBuffer);

	}
	if (!localInstance) {
		throw V8Exception("Parameter mismatch while calling constructor for DataView");
		return v8::Undefined();
	}

	v8::Handle<v8::Function> retCtor = V8DataView::getTmpl()->GetFunction();
	v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

	struct V8DataView::V8DataViewPrivate* retPrivData = new V8DataView::V8DataViewPrivate();
	retPrivData->nativeObj = localInstance;

	retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

	retObj.MakeWeak(0, V8DataView::jsDestructor);
	return retObj;
}

v8::Handle<v8::Value> V8DataView::getInt8Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 1 &&
	           args[0]->IsUint32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();

		char retVal = privData->nativeObj->getInt8(localByteOffset);

		return v8::Number::New(retVal);
	}
	throw V8Exception("Parameter mismatch while calling getInt8");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::getUint8Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 1 &&
	           args[0]->IsUint32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();

		unsigned char retVal = privData->nativeObj->getUint8(localByteOffset);

		return v8::Number::New(retVal);
	}
	throw V8Exception("Parameter mismatch while calling getUint8");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::getInt16Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsBoolean()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		bool localLittleEndian = args[1]->ToBoolean()->BooleanValue();

		short retVal = privData->nativeObj->getInt16(localByteOffset, localLittleEndian);

		return v8::Number::New(retVal);
	} else if (args.Length() == 1 &&
	           args[0]->IsUint32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();

		short retVal = privData->nativeObj->getInt16(localByteOffset);

		return v8::Number::New(retVal);
	}
	throw V8Exception("Parameter mismatch while calling getInt16");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::getUint16Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsBoolean()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		bool localLittleEndian = args[1]->ToBoolean()->BooleanValue();

		unsigned short retVal = privData->nativeObj->getUint16(localByteOffset, localLittleEndian);

		return v8::Number::New(retVal);
	} else if (args.Length() == 1 &&
	           args[0]->IsUint32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();

		unsigned short retVal = privData->nativeObj->getUint16(localByteOffset);

		return v8::Number::New(retVal);
	}
	throw V8Exception("Parameter mismatch while calling getUint16");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::getInt32Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsBoolean()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		bool localLittleEndian = args[1]->ToBoolean()->BooleanValue();

		long retVal = privData->nativeObj->getInt32(localByteOffset, localLittleEndian);

		return v8::Number::New(retVal);
	} else if (args.Length() == 1 &&
	           args[0]->IsUint32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();

		long retVal = privData->nativeObj->getInt32(localByteOffset);

		return v8::Number::New(retVal);
	}
	throw V8Exception("Parameter mismatch while calling getInt32");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::getUint32Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsBoolean()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		bool localLittleEndian = args[1]->ToBoolean()->BooleanValue();

		unsigned long retVal = privData->nativeObj->getUint32(localByteOffset, localLittleEndian);

		return v8::Number::New(retVal);
	} else if (args.Length() == 1 &&
	           args[0]->IsUint32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();

		unsigned long retVal = privData->nativeObj->getUint32(localByteOffset);

		return v8::Number::New(retVal);
	}
	throw V8Exception("Parameter mismatch while calling getUint32");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::getFloat32Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsBoolean()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		bool localLittleEndian = args[1]->ToBoolean()->BooleanValue();

		float retVal = privData->nativeObj->getFloat32(localByteOffset, localLittleEndian);

		return v8::Number::New(retVal);
	} else if (args.Length() == 1 &&
	           args[0]->IsUint32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();

		float retVal = privData->nativeObj->getFloat32(localByteOffset);

		return v8::Number::New(retVal);
	}
	throw V8Exception("Parameter mismatch while calling getFloat32");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::getFloat64Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsBoolean()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		bool localLittleEndian = args[1]->ToBoolean()->BooleanValue();

		double retVal = privData->nativeObj->getFloat64(localByteOffset, localLittleEndian);

		return v8::Number::New(retVal);
	} else if (args.Length() == 1 &&
	           args[0]->IsUint32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();

		double retVal = privData->nativeObj->getFloat64(localByteOffset);

		return v8::Number::New(retVal);
	}
	throw V8Exception("Parameter mismatch while calling getFloat64");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::setInt8Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsInt32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		char localValue = args[1]->ToNumber()->Int32Value();

		privData->nativeObj->setInt8(localByteOffset, localValue);

		return v8::Undefined();
	}
	throw V8Exception("Parameter mismatch while calling setInt8");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::setUint8Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsUint32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		unsigned char localValue = args[1]->ToNumber()->Uint32Value();

		privData->nativeObj->setUint8(localByteOffset, localValue);

		return v8::Undefined();
	}
	throw V8Exception("Parameter mismatch while calling setUint8");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::setInt16Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 3 &&
	           args[0]->IsUint32() &&
	           args[1]->IsInt32() &&
	           args[2]->IsBoolean()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		short localValue = args[1]->ToNumber()->Int32Value();
		bool localLittleEndian = args[2]->ToBoolean()->BooleanValue();

		privData->nativeObj->setInt16(localByteOffset, localValue, localLittleEndian);

		return v8::Undefined();
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsInt32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		short localValue = args[1]->ToNumber()->Int32Value();

		privData->nativeObj->setInt16(localByteOffset, localValue);

		return v8::Undefined();
	}
	throw V8Exception("Parameter mismatch while calling setInt16");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::setUint16Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 3 &&
	           args[0]->IsUint32() &&
	           args[1]->IsUint32() &&
	           args[2]->IsBoolean()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		unsigned short localValue = args[1]->ToNumber()->Uint32Value();
		bool localLittleEndian = args[2]->ToBoolean()->BooleanValue();

		privData->nativeObj->setUint16(localByteOffset, localValue, localLittleEndian);

		return v8::Undefined();
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsUint32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		unsigned short localValue = args[1]->ToNumber()->Uint32Value();

		privData->nativeObj->setUint16(localByteOffset, localValue);

		return v8::Undefined();
	}
	throw V8Exception("Parameter mismatch while calling setUint16");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::setInt32Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 3 &&
	           args[0]->IsUint32() &&
	           args[1]->IsInt32() &&
	           args[2]->IsBoolean()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		long localValue = args[1]->ToNumber()->Int32Value();
		bool localLittleEndian = args[2]->ToBoolean()->BooleanValue();

		privData->nativeObj->setInt32(localByteOffset, localValue, localLittleEndian);

		return v8::Undefined();
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsInt32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		long localValue = args[1]->ToNumber()->Int32Value();

		privData->nativeObj->setInt32(localByteOffset, localValue);

		return v8::Undefined();
	}
	throw V8Exception("Parameter mismatch while calling setInt32");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::setUint32Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 3 &&
	           args[0]->IsUint32() &&
	           args[1]->IsUint32() &&
	           args[2]->IsBoolean()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		unsigned long localValue = args[1]->ToNumber()->Uint32Value();
		bool localLittleEndian = args[2]->ToBoolean()->BooleanValue();

		privData->nativeObj->setUint32(localByteOffset, localValue, localLittleEndian);

		return v8::Undefined();
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsUint32()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		unsigned long localValue = args[1]->ToNumber()->Uint32Value();

		privData->nativeObj->setUint32(localByteOffset, localValue);

		return v8::Undefined();
	}
	throw V8Exception("Parameter mismatch while calling setUint32");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::setFloat32Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 3 &&
	           args[0]->IsUint32() &&
	           args[1]->IsNumber() &&
	           args[2]->IsBoolean()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		float localValue = args[1]->ToNumber()->Value();
		bool localLittleEndian = args[2]->ToBoolean()->BooleanValue();

		privData->nativeObj->setFloat32(localByteOffset, localValue, localLittleEndian);

		return v8::Undefined();
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsNumber()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		float localValue = args[1]->ToNumber()->Value();

		privData->nativeObj->setFloat32(localByteOffset, localValue);

		return v8::Undefined();
	}
	throw V8Exception("Parameter mismatch while calling setFloat32");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8DataView::setFloat64Callback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DataViewPrivate* privData = V8DOM::toClassPtr<V8DataViewPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 3 &&
	           args[0]->IsUint32() &&
	           args[1]->IsNumber() &&
	           args[2]->IsBoolean()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		double localValue = args[1]->ToNumber()->Value();
		bool localLittleEndian = args[2]->ToBoolean()->BooleanValue();

		privData->nativeObj->setFloat64(localByteOffset, localValue, localLittleEndian);

		return v8::Undefined();
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsNumber()) {
		unsigned long localByteOffset = args[0]->ToNumber()->Uint32Value();
		double localValue = args[1]->ToNumber()->Value();

		privData->nativeObj->setFloat64(localByteOffset, localValue);

		return v8::Undefined();
	}
	throw V8Exception("Parameter mismatch while calling setFloat64");
	return v8::Undefined();
}
bool V8DataView::hasInstance(v8::Handle<v8::Value> value) {
	return getTmpl()->HasInstance(value);
}

}
}