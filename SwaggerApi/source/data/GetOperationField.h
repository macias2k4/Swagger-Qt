#ifndef GETOPERATIONFIELD_H
#define GETOPERATIONFIELD_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <OperationFieldBase.h>

namespace Swagger {
namespace Data {

/// \brief GetOperationField -> Get operation object
class GetOperationField : public Base::OperationFieldBase {
    Q_OBJECT
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit GetOperationField ( QObject *parent = 0 );
    ~GetOperationField ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief operationType -> return type of operation
    virtual Base::OperationFieldBase::OperationType operationType ( ) const override;

    // - property

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property

};

} // Data
} // Swagger

//Q_DECLARE_METATYPE ( Swagger::Data::GetOperationField )

#endif // GETOPERATIONFIELD_H
