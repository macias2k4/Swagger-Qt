/**
  * \file     OperationFieldBase.h
  * \author   m.lamparski
  * \date     2017-04-18
  * \brief    File with base class for all Swagger Operation Field Type objects

*/
#ifndef OPERATIONFIELDBASE_H
#define OPERATIONFIELDBASE_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Qt
#include <QMetaEnum>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Swagger
#include <SwaggerFieldBase.h>
#include <ParameterFieldBase.h>
#include <ResponseField.h>

namespace Swagger {
namespace Base {

/// \brief The OperationFieldBase -> base class for all Swagger Operation Field Type objects
class OperationFieldBase : public SwaggerFieldBase {
    Q_OBJECT
    Q_PROPERTY ( QString path READ path WRITE setPath NOTIFY pathChanged )
    Q_PROPERTY ( QStringList tags READ tags WRITE setTags NOTIFY tagsChanged )
    Q_PROPERTY ( QString summary READ summary WRITE setSummary NOTIFY summaryChanged )
    Q_PROPERTY ( QString description READ description WRITE setDescription NOTIFY descriptionChanged )
    Q_PROPERTY ( QString operationId READ operationId WRITE setOperationId NOTIFY operationIdChanged )
    Q_PROPERTY ( QStringList consumes READ consumes WRITE setConsumes NOTIFY consumesChanged )
    Q_PROPERTY ( QStringList produces READ produces WRITE setProduces NOTIFY producesChanged )
    Q_PROPERTY ( QJsonValue Parameters READ parametersJson WRITE setParametersJson NOTIFY
                 setParametersDetected )
    Q_PROPERTY ( QJsonValue Responses READ responsesJson WRITE setResponsesJson NOTIFY
                 setResponsesDetected )
    Q_PROPERTY ( QStringList schemes READ schemes WRITE setSchemes NOTIFY schemesChanged )
    Q_PROPERTY ( bool deprecated READ deprecated WRITE setDeprecated NOTIFY deprecatedChanged )

public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // types
    enum class OperationType {
        Get
    };
    Q_ENUM ( OperationType )
    /// \brief operationTypeValueToString -> return enum value as string
    static QString operationTypeValueToString ( OperationType value );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit OperationFieldBase ( QObject *parent = 0 );
    ~OperationFieldBase ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief isFieldAlreadySet -> implementing virtual method of SwaggerFieldBase
    bool isFieldAlreadySet ( ) const override;

    /// \brief operationType -> return type of operation
    virtual Base::OperationFieldBase::OperationType operationType ( ) const = 0;
    /// \brief operationTypeAsString -> return type of operation as string
    QString operationTypeAsString ( ) const;
    /// \brief clear -> clear properties of current field
    virtual void clear ( ) override;

    // - property

    QString path ( ) const;
    void setPath ( QString path );

    QStringList tags ( ) const;
    void setTags ( QStringList tags );

    QString summary ( ) const;
    void setSummary ( QString summary );

    QString description ( ) const;
    void setDescription ( QString description );

    QString operationId ( ) const;
    void setOperationId ( QString operationId );

    QStringList consumes ( ) const;
    void setConsumes ( QStringList consumes );

    QStringList produces ( ) const;
    void setProduces ( QStringList produces );

    QJsonValue parametersJson ( ) const;
    void setParametersJson ( QJsonValue parametersJson );
    QList < Base::ParameterFieldBase * >  parameters ( ) const;

    QJsonValue responsesJson ( ) const;
    void setResponsesJson ( QJsonValue responses );
    QList < Data::ResponseField * > responses ( ) const;

    QStringList schemes ( ) const;
    void setSchemes ( QStringList schemes );

    bool deprecated ( ) const;
    void setDeprecated ( bool deprecated );

    // -- parameters
    /// \brief isParameterAlreadyExist -> check is given parameter already added to this operation
    bool isParameterAlreadyExist ( Base::ParameterFieldBase *parameter );
    /// \brief addParameter -> adding new parameter object to list
    void addParameter ( Base::ParameterFieldBase *parameter );

    // -- responses
    /// \brief isResponseAlreadyExist -> check is given response already added to this operation
    bool isResponseAlreadyExist ( Data::ResponseField *response );
    /// \brief addResponse -> adding new response object to list
    void addResponse ( Data::ResponseField *response );

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals
    void tagsChanged ( QStringList tags );
    void summaryChanged ( QString summary );
    void descriptionChanged ( QString description );
    void operationIdChanged ( QString operationId );
    void consumesChanged ( QStringList consumes );
    void producesChanged ( QStringList produces );
    void setParametersDetected ( QJsonValue parametersJson );
    void schemesChanged ( QStringList schemes );
    void deprecatedChanged ( bool deprecated );
    void pathChanged ( QString path );
    void setResponsesDetected ( QJsonValue Responses );

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief _path -> A path on which API is serving this operation
    QString _path = QString ( );
    /// \brief _tags -> A list of tags for API documentation control. Grouping operations
    QStringList _tags;
    /// \brief _summary -> A short summary of what the operation does. Max 120 characters
    QString _summary = QString ( );
    /// \brief _description -> A verbose explanation of the operation behavior
    QString _description = QString ( );
    /// \brief _operationId -> Unique string used to identify the operation. The id MUST be unique
    /// among all operations described in the API
    QString _operationId = QString ( );
    /// \brief _consumes -> A list of MIME types the operation can consume. This overrides the
    /// consumes definition at the Swagger Object. An empty value MAY be used to clear the global
    /// definition
    QStringList _consumes;
    /// \brief _produces -> A list of MIME types the operation can produce. This overrides the
    /// produces definition at the Swagger Object. An empty value MAY be used to clear the global
    /// definition
    QStringList _produces;
    /// \brief _schemes -> The transfer protocol for the operation. Values MUST be from the list:
    /// "http", "https", "ws", "wss"
    QStringList _schemes;
    /// \brief _deprecated -> Declares this operation to be deprecated. Usage of the declared
    /// operation should be refrained. Default value is false
    bool _deprecated = false;
    /// \brief _parameters -> list of operation parameters
    QList < Base::ParameterFieldBase * > _parameters;
    /// \brief _responses -> list of operation responses, depending of response code
    QList < Data::ResponseField * > _responses;
};

} // Base
} // Swagger

#endif // OPERATIONFIELDBASE_H
