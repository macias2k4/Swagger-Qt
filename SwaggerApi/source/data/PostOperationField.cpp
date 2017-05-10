#include "PostOperationField.h"

namespace Swagger {
namespace Data {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
PostOperationField::PostOperationField ( QObject *parent )
    : Base::OperationFieldBase ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
PostOperationField::~PostOperationField ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
Base::OperationFieldBase::OperationType PostOperationField::operationType ( ) const {
    return OperationType::Post;
}

} // Data
} // Swagger
