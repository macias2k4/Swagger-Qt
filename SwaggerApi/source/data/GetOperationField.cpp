#include "GetOperationField.h"

namespace Swagger {
namespace Data {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
GetOperationField::GetOperationField ( QObject *parent )
    : Base::OperationFieldBase ( parent ) {
}
//// ────────────────────────────────────────────────────────────────────────────────────────────── //
//GetOperationField::GetOperationField ( const GetOperationField &object )
//    : Base::OperationFieldBase ( object ) {
//}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
GetOperationField::~GetOperationField ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
Base::OperationFieldBase::OperationType GetOperationField::operationType ( ) const {
    return OperationType::Get;
}

} // Data
} // Swagger
