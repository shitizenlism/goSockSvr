// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#include "message.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace pb {
class PingDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Ping> _instance;
} _Ping_default_instance_;
class SceneDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Scene> _instance;
} _Scene_default_instance_;
}  // namespace pb
static void InitDefaultsscc_info_Ping_message_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pb::_Ping_default_instance_;
    new (ptr) ::pb::Ping();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::pb::Ping::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Ping_message_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Ping_message_2eproto}, {}};

static void InitDefaultsscc_info_Scene_message_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pb::_Scene_default_instance_;
    new (ptr) ::pb::Scene();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::pb::Scene::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Scene_message_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Scene_message_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_message_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_message_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_message_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_message_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::pb::Ping, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::pb::Ping, timestamp_),
  PROTOBUF_FIELD_OFFSET(::pb::Ping, hello_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::pb::Scene, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::pb::Scene, timestamp_),
  PROTOBUF_FIELD_OFFSET(::pb::Scene, scenename_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::pb::Ping)},
  { 7, -1, sizeof(::pb::Scene)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pb::_Ping_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pb::_Scene_default_instance_),
};

const char descriptor_table_protodef_message_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\rmessage.proto\022\002pb\"(\n\004Ping\022\021\n\ttimeStamp"
  "\030\001 \001(\003\022\r\n\005hello\030\002 \001(\t\"-\n\005Scene\022\021\n\ttimeSt"
  "amp\030\001 \001(\003\022\021\n\tsceneName\030\002 \001(\tB\007Z\005./;pbb\006p"
  "roto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_message_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_message_2eproto_sccs[2] = {
  &scc_info_Ping_message_2eproto.base,
  &scc_info_Scene_message_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_message_2eproto_once;
static bool descriptor_table_message_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_message_2eproto = {
  &descriptor_table_message_2eproto_initialized, descriptor_table_protodef_message_2eproto, "message.proto", 125,
  &descriptor_table_message_2eproto_once, descriptor_table_message_2eproto_sccs, descriptor_table_message_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_message_2eproto::offsets,
  file_level_metadata_message_2eproto, 2, file_level_enum_descriptors_message_2eproto, file_level_service_descriptors_message_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_message_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_message_2eproto), true);
namespace pb {

// ===================================================================

void Ping::InitAsDefaultInstance() {
}
class Ping::_Internal {
 public:
};

Ping::Ping()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:pb.Ping)
}
Ping::Ping(const Ping& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  hello_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_hello().empty()) {
    hello_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.hello_);
  }
  timestamp_ = from.timestamp_;
  // @@protoc_insertion_point(copy_constructor:pb.Ping)
}

void Ping::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Ping_message_2eproto.base);
  hello_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  timestamp_ = PROTOBUF_LONGLONG(0);
}

Ping::~Ping() {
  // @@protoc_insertion_point(destructor:pb.Ping)
  SharedDtor();
}

void Ping::SharedDtor() {
  hello_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Ping::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Ping& Ping::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Ping_message_2eproto.base);
  return *internal_default_instance();
}


void Ping::Clear() {
// @@protoc_insertion_point(message_clear_start:pb.Ping)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  hello_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  timestamp_ = PROTOBUF_LONGLONG(0);
  _internal_metadata_.Clear();
}

const char* Ping::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int64 timeStamp = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          timestamp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string hello = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_hello();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.Ping.hello"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Ping::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pb.Ping)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 timeStamp = 1;
  if (this->timestamp() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(1, this->_internal_timestamp(), target);
  }

  // string hello = 2;
  if (this->hello().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_hello().data(), static_cast<int>(this->_internal_hello().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "pb.Ping.hello");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_hello(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pb.Ping)
  return target;
}

size_t Ping::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pb.Ping)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string hello = 2;
  if (this->hello().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_hello());
  }

  // int64 timeStamp = 1;
  if (this->timestamp() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_timestamp());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Ping::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pb.Ping)
  GOOGLE_DCHECK_NE(&from, this);
  const Ping* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Ping>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pb.Ping)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pb.Ping)
    MergeFrom(*source);
  }
}

void Ping::MergeFrom(const Ping& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pb.Ping)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.hello().size() > 0) {

    hello_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.hello_);
  }
  if (from.timestamp() != 0) {
    _internal_set_timestamp(from._internal_timestamp());
  }
}

void Ping::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pb.Ping)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Ping::CopyFrom(const Ping& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pb.Ping)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Ping::IsInitialized() const {
  return true;
}

void Ping::InternalSwap(Ping* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  hello_.Swap(&other->hello_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(timestamp_, other->timestamp_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Ping::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Scene::InitAsDefaultInstance() {
}
class Scene::_Internal {
 public:
};

Scene::Scene()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:pb.Scene)
}
Scene::Scene(const Scene& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  scenename_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_scenename().empty()) {
    scenename_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.scenename_);
  }
  timestamp_ = from.timestamp_;
  // @@protoc_insertion_point(copy_constructor:pb.Scene)
}

void Scene::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Scene_message_2eproto.base);
  scenename_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  timestamp_ = PROTOBUF_LONGLONG(0);
}

Scene::~Scene() {
  // @@protoc_insertion_point(destructor:pb.Scene)
  SharedDtor();
}

void Scene::SharedDtor() {
  scenename_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Scene::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Scene& Scene::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Scene_message_2eproto.base);
  return *internal_default_instance();
}


void Scene::Clear() {
// @@protoc_insertion_point(message_clear_start:pb.Scene)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  scenename_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  timestamp_ = PROTOBUF_LONGLONG(0);
  _internal_metadata_.Clear();
}

const char* Scene::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int64 timeStamp = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          timestamp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string sceneName = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_scenename();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pb.Scene.sceneName"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Scene::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pb.Scene)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 timeStamp = 1;
  if (this->timestamp() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(1, this->_internal_timestamp(), target);
  }

  // string sceneName = 2;
  if (this->scenename().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_scenename().data(), static_cast<int>(this->_internal_scenename().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "pb.Scene.sceneName");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_scenename(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pb.Scene)
  return target;
}

size_t Scene::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pb.Scene)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string sceneName = 2;
  if (this->scenename().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_scenename());
  }

  // int64 timeStamp = 1;
  if (this->timestamp() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_timestamp());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Scene::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pb.Scene)
  GOOGLE_DCHECK_NE(&from, this);
  const Scene* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Scene>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pb.Scene)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pb.Scene)
    MergeFrom(*source);
  }
}

void Scene::MergeFrom(const Scene& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pb.Scene)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.scenename().size() > 0) {

    scenename_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.scenename_);
  }
  if (from.timestamp() != 0) {
    _internal_set_timestamp(from._internal_timestamp());
  }
}

void Scene::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pb.Scene)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Scene::CopyFrom(const Scene& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pb.Scene)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Scene::IsInitialized() const {
  return true;
}

void Scene::InternalSwap(Scene* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  scenename_.Swap(&other->scenename_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(timestamp_, other->timestamp_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Scene::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace pb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::pb::Ping* Arena::CreateMaybeMessage< ::pb::Ping >(Arena* arena) {
  return Arena::CreateInternal< ::pb::Ping >(arena);
}
template<> PROTOBUF_NOINLINE ::pb::Scene* Arena::CreateMaybeMessage< ::pb::Scene >(Arena* arena) {
  return Arena::CreateInternal< ::pb::Scene >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
