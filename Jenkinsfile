pipeline {

  agent any

  triggers {
     pollSCM('*/2 * * * *')
  }

  stages {
    stage('build') {
      steps {
        checkout scm
        sh './gradlew clean build'
      }
    }
  }
}
