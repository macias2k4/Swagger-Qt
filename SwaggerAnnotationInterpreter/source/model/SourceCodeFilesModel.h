#ifndef SOURCECODEFILESMODEL_H
#define SOURCECODEFILESMODEL_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Qt
#include <QObject>
#include <QFileInfoList>
#include <QDirIterator>
#include <QDebug>

namespace Swagger {
namespace Model {

/// \brief SourceCodeFilesModel -> model to keep list of source code files
class SourceCodeFilesModel : public QObject
{
    Q_OBJECT
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    explicit SourceCodeFilesModel ( QObject *parent = 0 );
    SourceCodeFilesModel ( const SourceCodeFilesModel &object );
    ~SourceCodeFilesModel ( );

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief fillModelWithRelativeRootPath -> fill model with source files
    void fillModelWithRelativeRootPath ( const QString &rootPath );

    // - property
    /// \brief sourceCodeFiles -> return source code files finded in set path
    QFileInfoList &sourceCodeFiles ( );
    /// \brief modelReadOnly -> return source code files finded in set path (ready only)
    QFileInfoList sourceCodeFilesReadOnly ( ) const;

signals:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // signals

public slots:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // slots

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    const QStringList _SourceCodeFilesExtension = { "*.h", "*.cpp" };
    /// \brief _sourceCodeFiles -> source code files finded in set path
    QFileInfoList _sourceCodeFiles;
    /// \brief _currentSourceCodeFile -> current adding source code file to list
    QFileInfo _currentSourceCodeFile;

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief _clearModel -> clear model
    void _clearModel ( );
    /// \brief _addCurrentSourceCodeFileToModel -> add current source file to model
    void _addCurrentSourceCodeFileToModel ( );
    /// \brief _isCurrentSourceCodeFileValid -> check is current source file correct to add to model
    bool _isCurrentSourceCodeFileValid ( );

};

} // Swagger
} // Model

#endif // SOURCECODEFILESMODEL_H
