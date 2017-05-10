/**
  * \file     PostOperationField.h
  * \author   m.lamparski
  * \date     2017-05-10
  * \version  $Revision$
  * \brief    File with class Post operation object

*/
#ifndef POSTOPERATIONFIELD_H
#define POSTOPERATIONFIELD_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger-Qt
#include <OperationFieldBase.h>

namespace Swagger {
namespace Data {

/// \brief PostOperationField -> Post operation object
class PostOperationField : public Base::OperationFieldBase {
    Q_OBJECT
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit PostOperationField ( QObject *parent = 0 );
    ~PostOperationField ( );

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

#endif // POSTOPERATIONFIELD_H
